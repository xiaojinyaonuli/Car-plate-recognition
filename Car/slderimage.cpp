/*****************************************
 * 作者: JS
 * 日期: 5.17
 * 类功能：轮播图功能
 * ***************************************/
#include "slderimage.h"
#include "ui_slderimage.h"
#include<QPropertyAnimation>
#include<QDebug>

SlderImage::SlderImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlderImage)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet(QString("#widget{background-color:#1A1A1A;border-style:none none solid none;border-color:blue;border-width:3px;}"));
    ui->first->setStyleSheet("QLabel{border-radius:5px;border:5px solid black;}");
    ui->Second->setStyleSheet("QLabel{border-radius:5px;border:5px solid black;}");
    ui->third->setStyleSheet("QLabel{border-radius:5px;border:5px solid black;}");
    ui->first->setPixmap(QPixmap(QString(":/image/sliderimage/one.png")));
    ui->first->setScaledContents(true);
    ui->Second->setPixmap(QPixmap(QString(":/image/sliderimage/two.jpg")));
    ui->Second->setScaledContents(true);
    ui->third->setPixmap(QPixmap(QString(":/image/sliderimage/three.jpg")));
    ui->third->setScaledContents(true);
    Time_Init_SliderImage();
}

SlderImage::~SlderImage()
{
    delete ui;
}

//初始化三个矩形区域 设置time相关
void SlderImage::Time_Init_SliderImage()
{
    r1.setRect(ui->first->x(),ui->first->y(),ui->first->width(),ui->first->height());
    r2.setRect(ui->Second->x(),ui->Second->y(),ui->Second->width(),ui->Second->height());
    r3.setRect(ui->third->x(),ui->third->y(),ui->third->width(),ui->third->height());
    time=new QTimer();
    time->setInterval(2500);
    connect(time,&QTimer::timeout,this,&SlderImage::ProceedAnimation);
    time->start();


}


// label动画相关
void SlderImage::Startanimation(QObject *target, QRect startRect, QRect endRect, bool isRaise)
{
    QPropertyAnimation *ani = new QPropertyAnimation(target, "geometry");
        ani->setDuration(1000);
        ani->setStartValue(startRect);
        ani->setEndValue(endRect);
        ani->setEasingCurve(QEasingCurve::OutQuad);
        ani->start();
        QLabel* lab=dynamic_cast<QLabel*>(target);
        if(isRaise){
            lab->raise();
        }


}

//根据情况，设置图层显示顺序
void SlderImage::ProceedAnimation()
{
    qDebug()<<"1"<<ui->first->pos()<<endl;
    qDebug()<<"2"<<ui->Second->pos()<<endl;
    if(count==0)
    {

        Startanimation(ui->first,r1,r2,true);
        Startanimation(ui->Second,r2,r3,false);
        Startanimation(ui->third,r3,r1,false);


        count++;
    }
    else if(count==1)
    {
        Startanimation(ui->first,r2,r3,false);
        Startanimation(ui->Second,r3,r1,false);
        Startanimation(ui->third,r1,r2,true);
        count++;
    }
    else if(count==2)
    {
        Startanimation(ui->first,r3,r1,false);
        Startanimation(ui->Second,r1,r2,true);
        Startanimation(ui->third,r2,r3,false);

        count=0;
    }

}

void SlderImage::StartTime()
{
    time->start();

}


