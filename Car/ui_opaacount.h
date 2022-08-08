/********************************************************************************
** Form generated from reading UI file 'opaacount.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPAACOUNT_H
#define UI_OPAACOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpaAcount
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tab;
    QLabel *label;

    void setupUi(QWidget *OpaAcount)
    {
        if (OpaAcount->objectName().isEmpty())
            OpaAcount->setObjectName(QString::fromUtf8("OpaAcount"));
        OpaAcount->resize(1055, 737);
        verticalLayout = new QVBoxLayout(OpaAcount);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(OpaAcount);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1031, 721));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tab = new QTableWidget(verticalLayoutWidget);
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMaximumSize(QSize(16777215, 600));

        verticalLayout_2->addWidget(tab);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(widget);


        retranslateUi(OpaAcount);

        QMetaObject::connectSlotsByName(OpaAcount);
    } // setupUi

    void retranslateUi(QWidget *OpaAcount)
    {
        OpaAcount->setWindowTitle(QCoreApplication::translate("OpaAcount", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpaAcount: public Ui_OpaAcount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPAACOUNT_H
