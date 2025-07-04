#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFormLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QScreen>
#include <QDebug>
#include <QMap>
#include <QSet>
#include <QFileDialog>
#include <QDir>
#include <QSpinBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentMapPath(":/maps/shenzhen.png")
{
    ui->setupUi(this);
    FirtPage_Welcome.show();
    auto f = [&](){
        this->show();
        FirtPage_Welcome.close();
    };
    connect(&FirtPage_Welcome,&Page_welcome::NextPage,this,f);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 引用深圳地铁线路数据结构
extern const QList<MetroLine> metroLines;

void MainWindow::on_sale_clicked()
{
    qDebug() << "售票按钮被点击";

    SaleWindow *saleWindow = new SaleWindow();
    connect(saleWindow, &SaleWindow::backToMainWindow, this, [this, saleWindow]() {
        this->show();
        saleWindow->deleteLater();
    });

    // 显示售票窗口并隐藏主窗口
    saleWindow->show();
    this->hide();

    // 居中显示窗口
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    saleWindow->move(screenGeometry.center() - saleWindow->rect().center());

    qDebug() << "售票窗口已显示";
}

void MainWindow::on_map_clicked()
{
    qDebug() << "地图按钮被点击";

    MapWindow *mapWindow = new MapWindow(nullptr, currentMapPath);
    connect(mapWindow, &MapWindow::backToMainWindow, this, [this, mapWindow]() {
        currentMapPath = mapWindow->getCurrentMapPath(); // 更新主窗口中的地图路径
        this->show();
        mapWindow->deleteLater();
    });

    // 显示地图窗口并隐藏主窗口
    mapWindow->show();
    this->hide();

    qDebug() << "地图窗口已显示";
}


void MainWindow::on_exit_clicked()
{
    exit(0);
}
