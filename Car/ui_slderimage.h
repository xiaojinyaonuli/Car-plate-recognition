/********************************************************************************
** Form generated from reading UI file 'slderimage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLDERIMAGE_H
#define UI_SLDERIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlderImage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *first;
    QLabel *Second;
    QLabel *third;

    void setupUi(QWidget *SlderImage)
    {
        if (SlderImage->objectName().isEmpty())
            SlderImage->setObjectName(QString::fromUtf8("SlderImage"));
        SlderImage->resize(1052, 250);
        verticalLayout = new QVBoxLayout(SlderImage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SlderImage);
        widget->setObjectName(QString::fromUtf8("widget"));
        first = new QLabel(widget);
        first->setObjectName(QString::fromUtf8("first"));
        first->setGeometry(QRect(0, 30, 371, 191));
        first->setStyleSheet(QString::fromUtf8(""));
        Second = new QLabel(widget);
        Second->setObjectName(QString::fromUtf8("Second"));
        Second->setGeometry(QRect(280, 0, 461, 241));
        Second->setStyleSheet(QString::fromUtf8(""));
        third = new QLabel(widget);
        third->setObjectName(QString::fromUtf8("third"));
        third->setGeometry(QRect(670, 30, 371, 191));
        third->setStyleSheet(QString::fromUtf8(""));
        first->raise();
        third->raise();
        Second->raise();

        verticalLayout->addWidget(widget);


        retranslateUi(SlderImage);

        QMetaObject::connectSlotsByName(SlderImage);
    } // setupUi

    void retranslateUi(QWidget *SlderImage)
    {
        SlderImage->setWindowTitle(QCoreApplication::translate("SlderImage", "Form", nullptr));
        first->setText(QString());
        Second->setText(QString());
        third->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlderImage: public Ui_SlderImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLDERIMAGE_H
