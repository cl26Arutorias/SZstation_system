#ifndef PAGE_WELCOME_H
#define PAGE_WELCOME_H

#include <QWidget>

namespace Ui {
class Page_welcome;
}

class Page_welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Page_welcome(QWidget *parent = nullptr);
    ~Page_welcome();

private slots:
    void on_pushButton_clicked();

signals:
    void NextPage();

private:
    Ui::Page_welcome *ui;
};

#endif // PAGE_WELCOME_H
