#include "sale.h"
#include <QDebug>
#include <QSet>
#include <QMap>
#include <QScreen>
#include <QGuiApplication>

// 深圳地铁线路数据
const QList<MetroLine> metroLines = {
    {"1号线", {"罗湖", "国贸", "老街", "大剧院", "科学馆", "华强路", "岗厦", "会展中心", "购物公园", "香蜜湖", "车公庙", "竹子林", "侨城东", "华侨城", "世界之窗"}},
    {"2号线", {"赤湾", "蛇口港", "海上世界", "水湾", "东角头", "湾厦", "海月", "登良", "后海", "科苑", "红树湾", "世界之窗", "侨城北", "深康", "安托山"}},
    {"3号线", {"福保", "益田", "石厦", "购物公园", "福田", "少年宫", "莲花村", "华新", "通新岭", "红岭", "老街", "晒布", "翠竹", "田贝", "水贝"}},
    {"4号线", {"福田口岸", "福民", "会展中心", "市民中心", "少年宫", "莲花北", "上梅林", "民乐", "白石龙", "深圳北站", "红山", "上塘", "龙胜", "龙华", "清湖"}},
    {"5号线", {"赤湾", "荔湾", "铁路公园", "妈湾", "前湾公园", "前湾", "桂湾", "前海湾", "临海", "宝华", "宝安中心", "翻身", "灵芝", "洪浪北", "兴东", "留仙洞", "西丽", "大学城", "塘朗", "长岭陂", "深圳北站", "民治", "五和", "坂田", "杨美", "上水径", "下水径", "布吉", "百鸽笼", "布心", "太安"}},
    {"6号线", {"科学馆", "通新岭", "体育中心", "八卦岭", "银湖", "翰岭", "梅林关", "深圳北站", "红山", "上芬", "元芬", "阳台山东", "官田", "上屋", "长圳", "凤凰城", "光明大街", "光明", "科学公园", "楼村", "红花山", "公明广场", "合水口", "薯田埔", "松岗公园", "溪头", "松岗"}},
    {"7号线", {"西丽湖", "西丽", "茶光", "珠光", "龙井", "桃源村", "深云", "安托山", "农林", "车公庙", "上沙", "沙尾", "石厦", "皇岗村", "福民", "皇岗口岸", "福邻", "赤尾", "华强南", "华强北", "华新", "黄木岗", "八卦岭", "红岭北", "笋岗", "洪湖", "田贝", "太安"}},
    {"8号线", {"莲塘", "梧桐山南", "沙头角", "海山", "盐田港西", "深外高中", "盐田路"}},
    {"9号线", {"前湾", "梦海", "怡海", "荔林", "南油西", "南油", "南山书城", "深大南", "粤海门", "高新南", "红树湾南", "深湾", "深圳湾公园", "下沙", "车公庙", "香梅", "景田", "梅景", "下梅林", "梅村", "上梅林", "孖岭", "银湖", "泥岗", "红岭北", "园岭", "红岭", "红岭南", "鹿丹村", "人民南", "向西村", "文锦"}},
    {"10号线", {"福田口岸", "福民", "岗厦", "岗厦北", "莲花村", "冬瓜岭", "孖岭", "雅宝", "南坑", "光雅园", "五和", "坂田北", "贝尔路", "华为", "岗头", "雪象", "甘坑", "凉帽山", "上李朗", "木古", "华南城", "禾花", "平湖", "双拥街"}},
    {"11号线", {"福田", "车公庙", "红树湾南", "后海", "南山", "前海湾", "宝安", "碧海湾", "机场", "机场北", "福永", "桥头", "塘尾", "马安山", "沙井", "后亭", "松岗", "碧头"}},
    {"12号线", {"左炮台东", "太子湾", "海上世界", "花果山", "四海", "南油", "南山", "桃园", "南头古城", "中山公园", "同乐南", "新安公园", "灵芝", "上川", "流塘", "宝安客运站", "臣田", "臣田北", "桃源居", "洲石路", "钟屋南", "黄田", "机场东", "兴围", "怀德", "福永", "桥头西", "福海西", "国展", "国展北", "海上田园东"}},
    {"14号线", {"岗厦北", "黄木岗", "罗湖北", "布吉", "石芽岭", "六约北", "四联", "坳背", "大运", "嶂背", "南约", "宝龙", "锦龙", "坪山围", "坪山广场", "坪山中心", "坑梓", "沙田"}},
    {"16号线", {"田心", "技术大学", "石井", "燕子湖", "沙壆", "东纵纪念馆", "坪山围", "新和", "六和", "坪山", "宝龙同乐", "龙东", "新塘围", "双龙", "龙园", "盛平", "尚景", "回龙埔", "愉园", "黄阁坑", "龙城公园", "数码城", "大运中心", "大运", "龙城公园停车场"}},
    {"20号线", {"机场北", "国展", "国展北", "会展城", "重庆路"}}
};

SaleWindow::SaleWindow(QWidget *parent)
    : QWidget(parent)
{
    // 设置窗口尺寸
    resize(750, 650);
    setWindowTitle("深圳地铁售票系统");
    setStyleSheet("background-color: #121212; color: #ffffff;");

    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(25, 25, 25, 25);
    mainLayout->setSpacing(20);

    // 标题
    QLabel *titleLabel = new QLabel("深圳地铁售票系统", this);
    titleLabel->setStyleSheet(
        "font-size: 26px; font-weight: bold; color: #ffffff;"
        "padding: 10px; border-bottom: 2px solid #4a76d0;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 线路选择区域
    QGroupBox *lineGroup = new QGroupBox("线路选择", this);
    lineGroup->setStyleSheet(
        "QGroupBox { font-weight: bold; font-size: 16px; color: #ffffff;"
        "background-color: #1e1e1e; border: 1px solid #333333; border-radius: 8px; margin-top: 10px;}"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center;"
        "padding: 0 10px; background-color: #2a2a2a; border-radius: 4px;}");

    QFormLayout *lineLayout = new QFormLayout(lineGroup);
    lineLayout->setSpacing(15);
    lineLayout->setContentsMargins(20, 30, 20, 20);

    // 起点线路下拉框
    QLabel *startLineLabel = new QLabel("起始线路:", lineGroup);
    startLineLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    startLineCombo = new QComboBox(lineGroup);
    for (const auto& line : metroLines) {
        startLineCombo->addItem(line.name);
    }
    startLineCombo->setStyleSheet(
        "QComboBox { height: 40px; font-size: 16px; padding: 0 15px; color: #ffffff;"
        "background-color: #2a2a2a; border: 1px solid #444444; border-radius: 5px;}"
        "QComboBox QAbstractItemView { background-color: #2a2a2a; color: #ffffff;"
        "selection-background-color: #4a76d0; border: 1px solid #444444;}"
        "QComboBox::drop-down { border: none;}");
    lineLayout->addRow(startLineLabel, startLineCombo);

    // 终点线路下拉框
    QLabel *endLineLabel = new QLabel("终点线路:", lineGroup);
    endLineLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    endLineCombo = new QComboBox(lineGroup);
    for (const auto& line : metroLines) {
        endLineCombo->addItem(line.name);
    }
    endLineCombo->setStyleSheet(startLineCombo->styleSheet());
    lineLayout->addRow(endLineLabel, endLineCombo);
    mainLayout->addWidget(lineGroup);

    // 站点选择区域
    QGroupBox *stationGroup = new QGroupBox("站点选择", this);
    stationGroup->setStyleSheet(lineGroup->styleSheet());

    QFormLayout *stationLayout = new QFormLayout(stationGroup);
    stationLayout->setSpacing(15);
    stationLayout->setContentsMargins(20, 30, 20, 20);

    // 起点站下拉框
    QLabel *startLabel = new QLabel("起始站:", stationGroup);
    startLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    startCombo = new QComboBox(stationGroup);
    startCombo->setStyleSheet(startLineCombo->styleSheet());
    stationLayout->addRow(startLabel, startCombo);

    // 终点站下拉框
    QLabel *endLabel = new QLabel("终点站:", stationGroup);
    endLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    endCombo = new QComboBox(stationGroup);
    endCombo->setStyleSheet(startLineCombo->styleSheet());
    stationLayout->addRow(endLabel, endCombo);

    // 站点线路信息
    startLineInfo = new QLabel("起始站线路: 未选择", stationGroup);
    startLineInfo->setStyleSheet("font-size: 14px; color: #cccccc;");
    stationLayout->addRow(startLineInfo);

    endLineInfo = new QLabel("终点站线路: 未选择", stationGroup);
    endLineInfo->setStyleSheet("font-size: 14px; color: #cccccc;");
    stationLayout->addRow(endLineInfo);

    // 人数选择
    QLabel *passengerLabel = new QLabel("购票人数:", stationGroup);
    passengerLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    passengerSpinBox = new QSpinBox(stationGroup);
    passengerSpinBox->setRange(1, 10);
    passengerSpinBox->setValue(1);
    passengerSpinBox->setStyleSheet(
        "QSpinBox { height: 40px; font-size: 16px; padding: 0 15px; color: #ffffff;"
        "background-color: #2a2a2a; border: 1px solid #444444; border-radius: 5px;}"
        "QSpinBox::up-button, QSpinBox::down-button { width: 30px;"
        "background-color: #3a3a3a; border: 1px solid #555555; border-radius: 3px;}"
        "QSpinBox::up-button:hover, QSpinBox::down-button:hover { background-color: #4a4a4a;}");
    stationLayout->addRow(passengerLabel, passengerSpinBox);

    // 票价显示
    fareLabel = new QLabel("票价: 0元", stationGroup);
    fareLabel->setStyleSheet(
        "font-size: 20px; font-weight: bold; color: #4caf50;"
        "background-color: #1a1f1c; border: 1px solid #2e7d32;"
        "border-radius: 6px; padding: 10px;");
    fareLabel->setAlignment(Qt::AlignCenter);
    stationLayout->addRow(fareLabel);
    mainLayout->addWidget(stationGroup);

    // 支付区域
    QGroupBox *paymentGroup = new QGroupBox("支付信息", this);
    paymentGroup->setStyleSheet(lineGroup->styleSheet());

    QFormLayout *paymentLayout = new QFormLayout(paymentGroup);
    paymentLayout->setSpacing(15);
    paymentLayout->setContentsMargins(20, 30, 20, 20);

    // 金额输入
    QLabel *amountLabel = new QLabel("支付金额:", paymentGroup);
    amountLabel->setStyleSheet("font-size: 16px; color: #ffffff;");

    amountInput = new QLineEdit(paymentGroup);
    amountInput->setPlaceholderText("请输入支付金额");
    amountInput->setValidator(new QIntValidator(0, 1000, amountInput));
    amountInput->setStyleSheet(
        "QLineEdit { height: 40px; font-size: 16px; padding: 0 15px; color: #ffffff;"
        "background-color: #2a2a2a; border: 1px solid #444444; border-radius: 5px;}");
    paymentLayout->addRow(amountLabel, amountInput);

    // 找零显示
    changeLabel = new QLabel("找零: 0元", paymentGroup);
    changeLabel->setStyleSheet(
        "font-size: 20px; font-weight: bold; color: #00bcd4;"
        "background-color: #102027; border: 1px solid #00838f;"
        "border-radius: 6px; padding: 10px;");
    changeLabel->setAlignment(Qt::AlignCenter);
    paymentLayout->addRow(changeLabel);
    mainLayout->addWidget(paymentGroup);

    // 按钮区域
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(25);

    // 返回按钮
    QPushButton *backButton = new QPushButton("返回主菜单", this);
    backButton->setStyleSheet(
        "QPushButton { background-color: #5f6368; border: none; color: white;"
        "padding: 12px 24px; font-size: 16px; font-weight: bold; border-radius: 6px;}"
        "QPushButton:hover { background-color: #4a4d52; transform: scale(1.05);}"
        "QPushButton:pressed { background-color: #3c3f43;}");
    backButton->setFixedSize(180, 45);

    // 确认支付按钮
    QPushButton *confirmButton = new QPushButton("确认支付", this);
    confirmButton->setStyleSheet(
        "QPushButton { background-color: #4a76d0; border: none; color: white;"
        "padding: 12px 24px; font-size: 16px; font-weight: bold; border-radius: 6px;}"
        "QPushButton:hover { background-color: #3d65b5; transform: scale(1.05);}"
        "QPushButton:pressed { background-color: #3559a0;}");
    confirmButton->setFixedSize(180, 45);

    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(confirmButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // 连接信号和槽
    auto updateStations = [=](QComboBox* lineCombo, QComboBox* stationCombo) {
        int index = lineCombo->currentIndex();
        if (index >= 0 && index < metroLines.size()) {
            stationCombo->clear();
            stationCombo->addItems(metroLines[index].stations);
        }
    };

    auto updateLineInfo = [=](QComboBox* stationCombo, QLabel* infoLabel) {
        QString station = stationCombo->currentText();
        if (!station.isEmpty()) {
            QStringList lines = getLinesForStation(station);
            infoLabel->setText(QString("%1站线路: %2")
                                   .arg(stationCombo == startCombo ? "起始" : "终点")
                                   .arg(lines.join(", ")));
        }
    };

    connect(startLineCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [=]() {
        updateStations(startLineCombo, startCombo);
        updateLineInfo(startCombo, startLineInfo);
        updateFare();
    });

    connect(endLineCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [=]() {
        updateStations(endLineCombo, endCombo);
        updateLineInfo(endCombo, endLineInfo);
        updateFare();
    });

    connect(startCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [=]() {
        updateLineInfo(startCombo, startLineInfo);
        updateFare();
    });

    connect(endCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [=]() {
        updateLineInfo(endCombo, endLineInfo);
        updateFare();
    });

    connect(passengerSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=]() {
        updateFare();
    });

    // 初始化站点列表
    updateStations(startLineCombo, startCombo);
    updateStations(endLineCombo, endCombo);
    updateFare();

    // 确认支付按钮
    connect(confirmButton, &QPushButton::clicked, [=]() {
        QString start = startCombo->currentText();
        QString end = endCombo->currentText();
        int passengerCount = passengerSpinBox->value();
        int farePerPerson = calculateFare(start, end);
        int totalFare = farePerPerson * passengerCount;

        bool ok;
        int amount = amountInput->text().toInt(&ok);

        if (!ok || amount < 0) {
            QMessageBox::warning(this, "输入错误", "请输入有效的支付金额");
            amountInput->setFocus();
            return;
        }

        if (amount < totalFare) {
            QMessageBox::warning(this, "金额不足",
                                 QString("支付金额不足！总票价%1元，还需%2元")
                                     .arg(totalFare).arg(totalFare - amount));
            amountInput->setFocus();
            return;
        }

        int change = amount - totalFare;
        changeLabel->setText(QString("找零: %1元").arg(change));

        QMessageBox msgBox(this);
        msgBox.setWindowTitle("支付成功");
        msgBox.setText(QString(
                           "<html><head/><body>"
                           "<p style='font-size:16px; color:#ffffff;'>购票成功！</p>"
                           "<p style='font-size:14px; color:#cccccc;'>从 <span style='color:#4caf50;'>%1</span> 到 <span style='color:#4caf50;'>%2</span> (共%3人)</p>"
                           "<p style='font-size:14px; color:#cccccc;'>单人票价: <span style='color:#4caf50;'>%4元</span> 总票价: <span style='color:#4caf50;'>%5元</span></p>"
                           "<p style='font-size:14px; color:#cccccc;'>支付: <span style='color:#4caf50;'>%6元</span></p>"
                           "<p style='font-size:14px; color:#cccccc;'>找零: <span style='color:#00bcd4;'>%7元</span></p>"
                           "</body></html>"
                           ).arg(start).arg(end).arg(passengerCount)
                           .arg(farePerPerson).arg(totalFare).arg(amount).arg(change));

        msgBox.setStyleSheet(
            "QMessageBox { background-color: #1e1e1e; border: 1px solid #333333; }"
            "QMessageBox QLabel { color: #ffffff; }"
            "QMessageBox QPushButton { background-color: #4a76d0; color: white;"
            "padding: 8px 16px; border-radius: 4px; min-width: 80px; }"
            "QMessageBox QPushButton:hover { background-color: #3d65b5; }");
        msgBox.exec();
    });

    // 返回按钮
    connect(backButton, &QPushButton::clicked, [this]() {
        this->close();
        emit backToMainWindow();
    });
}

SaleWindow::~SaleWindow() {}

QStringList SaleWindow::getLinesForStation(const QString& station) const
{
    QStringList lines;
    for (const auto& line : metroLines) {
        if (line.stations.contains(station)) {
            lines.append(line.name);
        }
    }
    return lines;
}

int SaleWindow::calculateFare(const QString& start, const QString& end) const
{
    int startIndex = -1, endIndex = -1;
    for (int i = 0; i < metroLines[0].stations.size(); i++) {
        if (metroLines[0].stations[i] == start) startIndex = i;
        if (metroLines[0].stations[i] == end) endIndex = i;
    }

    if (startIndex != -1 && endIndex != -1) {
        int stationCount = qAbs(endIndex - startIndex);
        if (stationCount <= 3) return 2;
        if (stationCount <= 6) return 3;
        if (stationCount <= 10) return 4;
        return 5;
    }
    return 4;
}

void SaleWindow::updateFare()
{
    QString start = startCombo->currentText();
    QString end = endCombo->currentText();
    int passengerCount = passengerSpinBox->value();

    if (!start.isEmpty() && !end.isEmpty()) {
        int farePerPerson = calculateFare(start, end);
        int totalFare = farePerPerson * passengerCount;
        fareLabel->setText(QString("票价: %1元 (共%2人)").arg(totalFare).arg(passengerCount));
        changeLabel->setText("找零: 0元");
    }
}
