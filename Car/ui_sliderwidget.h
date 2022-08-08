/********************************************************************************
** Form generated from reading UI file 'sliderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERWIDGET_H
#define UI_SLIDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "slderimage.h"

QT_BEGIN_NAMESPACE

class Ui_SliderWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    SlderImage *widget;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *SliderWidget)
    {
        if (SliderWidget->objectName().isEmpty())
            SliderWidget->setObjectName(QString::fromUtf8("SliderWidget"));
        SliderWidget->resize(1021, 311);
        verticalLayout = new QVBoxLayout(SliderWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget = new SlderImage(SliderWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(1020, 0));

        horizontalLayout->addWidget(widget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SliderWidget);

        QMetaObject::connectSlotsByName(SliderWidget);
    } // setupUi

    void retranslateUi(QWidget *SliderWidget)
    {
        SliderWidget->setWindowTitle(QCoreApplication::translate("SliderWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SliderWidget: public Ui_SliderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERWIDGET_H
