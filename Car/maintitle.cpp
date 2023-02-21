/*****************************************
 * 作者: JS
 * 日期:  2022.5.13
 * 类功能： 主界面自定义标题栏Titile
 * ***************************************/
#include "maintitle.h"
#include "ui_maintitle.h"
#include"customerclass.h"
#include<QDebug>
MainTitle::MainTitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTitle)
{
    ui->setupUi(this);

    ui->frame->setStyleSheet(QString("#frame{border-top-left-radius:15px;border-top-right-radius:15px;border-style:none none solid none;border-color:blue;border-width:2px;}"));

    Assistant::SetPushButtonQss(ui->min,5,"#FF00FF","","");
    Assistant::SetPushButtonQss(ui->max,5,"#FF00FF","","");
    Assistant::SetPushButtonQss(ui->close,5,"#FF00FF","","");
}

MainTitle::~MainTitle()
{
    delete ui;
}
