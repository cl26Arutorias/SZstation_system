#include "mapwindow.h"

// MapView 实现
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

// MapWindow 实现
MapWindow::MapWindow(QWidget *parent, const QString &mapPath)
    : QWidget(parent),
    currentMapPath(mapPath)
{
    // 设置窗口属性
    setWindowTitle("地图查看器");

    // 设置窗口尺寸（占据屏幕80%）
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int width = screenGeometry.width() * 0.8;
    int height = screenGeometry.height() * 0.8;
    resize(width, height);

    // 创建垂直布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    // 创建地图视图
    mapView = new MapView(this);
    layout->addWidget(mapView, 1); // 地图视图占据大部分空间

    // 创建按钮容器
    QWidget *buttonContainer = new QWidget(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonContainer);
    buttonLayout->setContentsMargins(0, 0, 0, 0);

    // 创建返回按钮
    backButton = new QPushButton(buttonContainer);
    backButton->setText("返回主菜单");
    backButton->setIcon(QIcon(":/icons/back.png")); // 可选的返回图标

    // 设置按钮样式
    backButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #5f6368;"
        "  border: none;"
        "  color: white;"
        "  padding: 12px 24px;"
        "  font-size: 16px;"
        "  font-weight: bold;"
        "  border-radius: 6px;"
        "  min-width: 180px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #4a4d52;"
        "  transform: scale(1.05);"
        "}"
        "QPushButton:pressed {"
        "  background-color: #3c3f43;"
        "}"
        );

    // 设置固定高度，但宽度自适应
    backButton->setFixedHeight(50);

    // 将按钮添加到布局
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton);
    buttonLayout->addStretch();

    // 将按钮容器添加到主布局
    layout->addWidget(buttonContainer);

    // 连接返回按钮信号
    connect(backButton, &QPushButton::clicked, this, &MapWindow::handleBackButton);

    // 居中显示窗口
    move(screenGeometry.center() - rect().center());

    // 加载地图
    qDebug() << "尝试加载地图:" << currentMapPath;
    if (!mapView->loadMap(currentMapPath)) {
        qDebug() << "默认地图加载失败，请求用户选择";

        // 如果默认地图加载失败，让用户选择
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        "打开地图文件",
                                                        QDir::homePath(),
                                                        "图像文件 (*.png *.jpg *.jpeg *.bmp)");

        if (!fileName.isEmpty()) {
            qDebug() << "用户选择的地图文件:" << fileName;
            if (mapView->loadMap(fileName)) {
                currentMapPath = fileName;
                qDebug() << "地图加载成功";
            } else {
                qDebug() << "用户选择的地图加载失败";
                QMessageBox::warning(this, "地图加载失败", "无法加载选定的地图文件");
            }
        } else {
            qDebug() << "用户取消了地图选择";
        }
    } else {
        qDebug() << "默认地图加载成功";
    }
}

MapWindow::~MapWindow()
{
    qDebug() << "地图窗口已关闭";
}

void MapWindow::handleBackButton()
{
    qDebug() << "返回主菜单按钮被点击";
    this->close();
    emit backToMainWindow();
}
