/********************************************************************************
** Form generated from reading UI file 'page_welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_WELCOME_H
#define UI_PAGE_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_welcome
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Page_welcome)
    {
        if (Page_welcome->objectName().isEmpty())
            Page_welcome->setObjectName("Page_welcome");
        Page_welcome->resize(600, 360);
        verticalLayout = new QVBoxLayout(Page_welcome);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(Page_welcome);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout->addWidget(label_3);

        label = new QLabel(Page_welcome);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setMargin(0);
        label->setIndent(0);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Page_welcome);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(24);
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(Page_welcome);
        pushButton->setObjectName("pushButton");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        pushButton->setFont(font3);
        pushButton->setAutoDefault(false);

        verticalLayout->addWidget(pushButton);


        retranslateUi(Page_welcome);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Page_welcome);
    } // setupUi

    void retranslateUi(QWidget *Page_welcome)
    {
        Page_welcome->setWindowTitle(QCoreApplication::translate("Page_welcome", "Welcome", nullptr));
#if QT_CONFIG(tooltip)
        Page_welcome->setToolTip(QCoreApplication::translate("Page_welcome", "\347\263\273\347\273\237\350\257\264\346\230\216", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("Page_welcome", "Welcome to My design", nullptr));
        label->setText(QCoreApplication::translate("Page_welcome", "\346\267\261\345\234\263\345\270\202\345\234\260\351\223\201\345\224\256\347\245\250\346\250\241\346\213\237\347\263\273\347\273\237", nullptr));
        label_2->setText(QCoreApplication::translate("Page_welcome", "\344\275\234\350\200\205\357\274\23224\347\272\247\346\234\272\345\231\250\344\272\272\344\270\216\346\231\272\350\203\275\350\243\205\345\244\207 \345\247\234\345\202\250\346\236\227", nullptr));
        pushButton->setText(QCoreApplication::translate("Page_welcome", "Next Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_welcome: public Ui_Page_welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_WELCOME_H
