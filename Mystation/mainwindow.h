#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <page_welcome.h>
#include "mapwindow.h"
#include "sale.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sale_clicked();

    void on_exit_clicked();

    void on_map_clicked();


private:
    Ui::MainWindow *ui;
    Page_welcome FirtPage_Welcome;
    QString currentMapPath;
};
#endif // MAINWINDOW_H
