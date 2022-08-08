/********************************************************************************
** Form generated from reading UI file 'maintitle.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTITLE_H
#define UI_MAINTITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTitle
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *icon;
    QLabel *wenzi;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QPushButton *max;
    QPushButton *close;

    void setupUi(QWidget *MainTitle)
    {
        if (MainTitle->objectName().isEmpty())
            MainTitle->setObjectName(QString::fromUtf8("MainTitle"));
        MainTitle->resize(1013, 45);
        MainTitle->setMaximumSize(QSize(16777215, 63));
        verticalLayout = new QVBoxLayout(MainTitle);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(MainTitle);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, 0);
        icon = new QLabel(frame);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setMinimumSize(QSize(30, 30));
        icon->setMaximumSize(QSize(30, 30));
        icon->setStyleSheet(QString::fromUtf8("image: url(:/image/icon.png);"));

        horizontalLayout->addWidget(icon);

        wenzi = new QLabel(frame);
        wenzi->setObjectName(QString::fromUtf8("wenzi"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wenzi->sizePolicy().hasHeightForWidth());
        wenzi->setSizePolicy(sizePolicy);
        wenzi->setMinimumSize(QSize(100, 30));
        wenzi->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        wenzi->setFont(font);
        wenzi->setStyleSheet(QString::fromUtf8("image: url(:/image/title.png);"));

        horizontalLayout->addWidget(wenzi);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(frame);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimumSize(QSize(20, 20));
        min->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(min);

        max = new QPushButton(frame);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMinimumSize(QSize(20, 20));
        max->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(max);

        close = new QPushButton(frame);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(20, 20));
        close->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(close);


        verticalLayout->addWidget(frame);


        retranslateUi(MainTitle);

        QMetaObject::connectSlotsByName(MainTitle);
    } // setupUi

    void retranslateUi(QWidget *MainTitle)
    {
        MainTitle->setWindowTitle(QCoreApplication::translate("MainTitle", "Form", nullptr));
        icon->setText(QString());
        wenzi->setText(QString());
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainTitle: public Ui_MainTitle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTITLE_H
