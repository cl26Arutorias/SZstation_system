#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>
#include <QPainter>
#include <QFont>
#include <QWheelEvent>

// 地图视图类
class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = nullptr);

    // 加载地图文件
    bool loadMap(const QString &filePath);

    // 缩放控制
    void zoomIn();
    void zoomOut();
    void resetZoom();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *mapItem;
};

// 地图窗口类
class MapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr, const QString &mapPath = QString());
    ~MapWindow();

    QString getCurrentMapPath() const { return currentMapPath; }

signals:
    void backToMainWindow(); // 返回主窗口信号

private slots:
    void handleBackButton();

private:
    MapView *mapView;
    QPushButton *backButton;
    QString currentMapPath;
};

#endif // MAPWINDOW_H
