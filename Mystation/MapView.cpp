#include "mapview.h"
#include <QWheelEvent>
#include <QDebug>
#include <QApplication>

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    mapItem(nullptr)
{
    // 设置视图属性
    setRenderHint(QPainter::SmoothPixmapTransform, true);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);

    // 设置场景
    setScene(scene);

    // 设置样式
    setStyleSheet("background-color: #f0f0f0;");
}

bool MapView::loadMap(const QString &filePath)
{
    QPixmap map;
    if (!map.load(filePath)) {
        qWarning() << "地图文件加载失败:" << filePath;

        // 创建错误提示图像
        map = QPixmap(800, 600);
        map.fill(Qt::white);
        QPainter painter(&map);
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 16));
        painter.drawText(map.rect(), Qt::AlignCenter,
                         QString("地图加载失败\n%1").arg(filePath));
    }

    // 移除旧地图（如果存在）
    if (mapItem) {
        scene->removeItem(mapItem);
        delete mapItem;
        mapItem = nullptr;
    }

    // 添加新地图
    mapItem = scene->addPixmap(map);
    scene->setSceneRect(map.rect());

    // 重置视图
    resetTransform();
    centerOn(mapItem);

    return true;
}

void MapView::zoomIn()
{
    scale(1.2, 1.2);
}

void MapView::zoomOut()
{
    scale(1.0/1.2, 1.0/1.2);
}

void MapView::resetZoom()
{
    resetTransform();
}

void MapView::wheelEvent(QWheelEvent *event)
{
    // 缩放因子
    double zoomFactor = 1.15;
    if (event->angleDelta().y() > 0) {
        // 放大
        scale(zoomFactor, zoomFactor);
    } else {
        // 缩小
        scale(1.0 / zoomFactor, 1.0 / zoomFactor);
    }
}
