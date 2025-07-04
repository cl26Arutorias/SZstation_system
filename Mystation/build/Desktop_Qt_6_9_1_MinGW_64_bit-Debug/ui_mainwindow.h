/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *sale;
    QLabel *label;
    QPushButton *map;
    QPushButton *exit;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        sale = new QPushButton(centralwidget);
        sale->setObjectName("sale");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        sale->setFont(font);

        gridLayout->addWidget(sale, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        label->setIndent(0);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        map = new QPushButton(centralwidget);
        map->setObjectName("map");
        map->setFont(font);

        gridLayout->addWidget(map, 5, 0, 1, 1);

        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setFont(font);

        gridLayout->addWidget(exit, 7, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        label_2->setFont(font2);
        label_2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\267\261\345\234\263\345\270\202\345\234\260\351\223\201\345\224\256\347\245\250\346\250\241\346\213\237\347\263\273\347\273\237", nullptr));
        sale->setText(QCoreApplication::translate("MainWindow", "\350\264\255\347\245\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\267\261\345\234\263\345\270\202\345\234\260\351\223\201\345\224\256\347\245\250\346\250\241\346\213\237\347\263\273\347\273\237", nullptr));
        map->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\346\237\245\350\257\242", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\277\347\224\250\350\257\264\346\230\216\357\274\232\347\202\271\345\207\273\345\234\260\345\233\276\346\237\245\350\257\242\350\277\233\345\205\245\346\267\261\345\234\263\345\270\202\345\234\260\351\223\201\345\234\260\345\233\276\346\237\245\350\257\242\345\257\271\345\272\224\347\253\231\347\202\271\357\274\214\347\202\271\345\207\273\350\264\255\347\245\250\345\220\216\350\277\233\345\205\245\345\224\256\347\245\250\345\244\204\357\274\214\345\217\257\346\240\271\346\215\256\345\234\260\351\223\201\347\272\277\350\267\257\346\210\226\350\200\205\345\234\260\351\223\201\347\253\231\347\202\271\350\277\233\350\241\214\347\255\233\351\200\211\357\274\214\345\241\253\345\206\231\344\272\272\346\225\260\344\270\216\351\207\221\351\242\235\346\226\271\345\217\257\345\210\244\346\226\255\345\207\272\347\245\250\343\200\202</span></p><p><span style=\" font-size:10pt;\">\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\346\234\254\347\263\273"
                        "\347\273\237\346\232\202\345\244\204\344\272\216\347\240\224\345\217\221\347\212\266\346\200\201\357\274\214\345\234\260\351\223\201\347\245\250\344\273\267\350\256\241\347\256\227\345\237\272\344\272\216\347\256\200\345\215\225\347\232\204\345\271\277\346\220\234\357\274\210BFS\357\274\211\357\274\214\350\256\241\347\256\227\345\207\272\346\234\200\347\237\255\350\267\257\345\276\204\347\253\231\347\202\271\346\225\260\357\274\214\347\256\200\345\214\226\350\256\241\347\256\227\345\260\206\347\253\231\347\202\271\351\227\264\350\267\235\345\271\263\345\235\207\344\270\2721.5km\357\274\214\345\217\202\350\200\203\346\267\261\345\234\263\345\234\260\351\223\201\344\272\244\351\200\232\350\256\241\350\264\271\346\240\207\345\207\206\346\240\271\346\215\256\350\267\235\347\246\273\350\256\241\347\256\227\347\245\250\344\273\267\357\274\214\344\273\205\344\275\234\344\270\272\345\224\256\347\245\250\345\217\202\350\200\203\343\200\202</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
