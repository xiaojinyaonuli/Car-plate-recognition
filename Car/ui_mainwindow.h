/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "maintitle.h"
#include "slderimage.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *maindisplay;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    MainTitle *title;
    SlderImage *lunbo;
    QWidget *widget_2;
    QWidget *btn;
    QWidget *btn2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1070, 676);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        maindisplay = new QWidget(centralwidget);
        maindisplay->setObjectName(QString::fromUtf8("maindisplay"));
        verticalLayoutWidget = new QWidget(maindisplay);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1054, 661));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        title = new MainTitle(verticalLayoutWidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setMinimumSize(QSize(0, 45));
        title->setMaximumSize(QSize(16777215, 45));

        verticalLayout_2->addWidget(title);

        lunbo = new SlderImage(verticalLayoutWidget);
        lunbo->setObjectName(QString::fromUtf8("lunbo"));
        lunbo->setMinimumSize(QSize(0, 250));
        lunbo->setMaximumSize(QSize(16777215, 250));

        verticalLayout_2->addWidget(lunbo);

        widget_2 = new QWidget(verticalLayoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        btn = new QWidget(widget_2);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(620, 10, 300, 301));
        btn->setMinimumSize(QSize(300, 0));
        btn->setMaximumSize(QSize(300, 16777215));
        btn2 = new QWidget(widget_2);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(140, 10, 300, 301));
        btn2->setMinimumSize(QSize(300, 0));
        btn2->setMaximumSize(QSize(300, 16777215));

        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(maindisplay);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
