#include "page_welcome.h"
#include "ui_page_welcome.h"

Page_welcome::Page_welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_welcome)
{
    ui->setupUi(this);
}

Page_welcome::~Page_welcome()
{
    delete ui;
}

void Page_welcome::on_pushButton_clicked()
{
    emit NextPage();
}

