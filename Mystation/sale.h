#ifndef SALE_H
#define SALE_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFormLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

// 深圳地铁线路数据结构
struct MetroLine {
    QString name;
    QStringList stations;
};

// 声明全局的地铁线路数据
extern const QList<MetroLine> metroLines;

class SaleWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SaleWindow(QWidget *parent = nullptr);
    ~SaleWindow();

signals:
    void backToMainWindow(); // 返回主窗口信号

private slots:
    void updateFare(); // 更新票价显示

private:
    // 获取站点所在的线路
    QStringList getLinesForStation(const QString& station) const;
    // 计算票价
    int calculateFare(const QString& start, const QString& end) const;

    // 控件
    QComboBox *startLineCombo;
    QComboBox *endLineCombo;
    QComboBox *startCombo;
    QComboBox *endCombo;
    QSpinBox *passengerSpinBox;
    QLabel *fareLabel;
    QLabel *changeLabel;
    QLineEdit *amountInput;
    QLabel *startLineInfo;
    QLabel *endLineInfo;
};

#endif // SALE_H
