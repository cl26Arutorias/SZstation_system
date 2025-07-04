#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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

#endif // MAPVIEW_H
