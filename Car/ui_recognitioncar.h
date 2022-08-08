/********************************************************************************
** Form generated from reading UI file 'recognitioncar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNITIONCAR_H
#define UI_RECOGNITIONCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecognitionCar
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *recar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *carimage;
    QWidget *oper;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tab;

    void setupUi(QWidget *RecognitionCar)
    {
        if (RecognitionCar->objectName().isEmpty())
            RecognitionCar->setObjectName(QString::fromUtf8("RecognitionCar"));
        RecognitionCar->resize(1055, 737);
        verticalLayout = new QVBoxLayout(RecognitionCar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(RecognitionCar);
        widget->setObjectName(QString::fromUtf8("widget"));
        recar = new QWidget(widget);
        recar->setObjectName(QString::fromUtf8("recar"));
        recar->setGeometry(QRect(0, 0, 1037, 719));
        recar->setMinimumSize(QSize(800, 0));
        horizontalLayoutWidget = new QWidget(recar);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1041, 441));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 10, 3, 0);
        carimage = new QLabel(horizontalLayoutWidget);
        carimage->setObjectName(QString::fromUtf8("carimage"));
        carimage->setMinimumSize(QSize(950, 0));
        carimage->setMaximumSize(QSize(950, 16777215));

        horizontalLayout_4->addWidget(carimage);

        oper = new QWidget(horizontalLayoutWidget);
        oper->setObjectName(QString::fromUtf8("oper"));

        horizontalLayout_4->addWidget(oper);

        horizontalLayoutWidget_2 = new QWidget(recar);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 440, 1041, 281));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tab = new QTableWidget(horizontalLayoutWidget_2);
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(tab);


        verticalLayout->addWidget(widget);


        retranslateUi(RecognitionCar);

        QMetaObject::connectSlotsByName(RecognitionCar);
    } // setupUi

    void retranslateUi(QWidget *RecognitionCar)
    {
        RecognitionCar->setWindowTitle(QCoreApplication::translate("RecognitionCar", "Form", nullptr));
        carimage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecognitionCar: public Ui_RecognitionCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNITIONCAR_H
