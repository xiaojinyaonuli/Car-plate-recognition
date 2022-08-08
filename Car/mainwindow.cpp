#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"customerclass.h"
#include"recognitioncar.h"
#include<QString>
#include<QGraphicsEffect>
#include<QMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,regcar(nullptr)
    ,account(nullptr)
    ,Recogpage(nullptr)
    ,_opaacount(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->maindisplay->setStyleSheet(QString("#maindisplay{background-color:#F0FFFF;border-radius:15px;}"));

    initshadow();
    initBiguttons();
    btnsConnect();
}


void MainWindow::initshadow()
{

    QGraphicsDropShadowEffect  *widget_shadow=new QGraphicsDropShadowEffect(this);
    widget_shadow->setOffset(0,0);

    widget_shadow->setColor(QColor("#080808"));

    widget_shadow->setBlurRadius(13);

    ui->maindisplay->setGraphicsEffect(widget_shadow);
}

void MainWindow::initBiguttons()
{
    ui->btn=new BigButton(":/image/shi2.png","车辆识别",ui->widget_2);
    ui->btn2=new BigButton(":/image/jiesuan.png","账单信息",ui->widget_2);
    regcar=static_cast<BigButton *>(ui->btn);
    account=static_cast<BigButton *>(ui->btn2);
    QHBoxLayout *hlayout=new QHBoxLayout(ui->widget_2);
    ui->widget_2->setLayout(hlayout);
    hlayout->setContentsMargins(5,5,5,5);
    hlayout->addWidget(ui->btn);
    hlayout->addWidget(ui->btn2);
}

void MainWindow::btnsConnect()
{

    connect(regcar,&BigButton::clicked,this,[=](){
        if(nullptr==Recogpage){
            Recogpage=new RecognitionCar(nullptr);
            //Recogpage->showNormal();
            if(nullptr==Recogpageani)
            {
                Recogpageani=new QPropertyAnimation(Recogpage,"windowOpacity");
                Recogpageani->setDuration(Regispage_DURATION);
                Recogpageani->setStartValue(0.0);
                Recogpageani->setEndValue(1);

            }
            Recogpageani->start();
            Recogpage->showNormal();
        }else{
            Recogpageani=new QPropertyAnimation(Recogpage,"windowOpacity");
            Recogpageani->setDuration(Regispage_DURATION);
            Recogpageani->setStartValue(0.0);
            Recogpageani->setEndValue(1);
            Recogpageani->start();
            Recogpage->showNormal();
        }

    });
    connect(account,&BigButton::clicked,this,[=](){
        qDebug()<<"点击账户"<<endl;
        if(nullptr==_opaacount){
            _opaacount=new OpaAcount(nullptr);
            //Recogpage->showNormal();
            if(nullptr==opaacountani)
            {
                opaacountani=new QPropertyAnimation(_opaacount,"windowOpacity");
                opaacountani->setDuration(Regispage_DURATION);
                opaacountani->setStartValue(0.0);
                opaacountani->setEndValue(1);

            }
            opaacountani->start();
            _opaacount->showNormal();
        }else{
            opaacountani=new QPropertyAnimation(_opaacount,"windowOpacity");
            opaacountani->setDuration(Regispage_DURATION);
            opaacountani->setStartValue(0.0);
            opaacountani->setEndValue(1);
            opaacountani->start();
            _opaacount->showNormal();
        }

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QPoint off_temp;
        off_temp=event->globalPos()-offest;
        move(off_temp);
    }
    QWidget::mouseMoveEvent(event);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        offest=event->globalPos()-pos();
    }
    QWidget::mousePressEvent(event);



}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
   QWidget::mouseReleaseEvent(event);
}

void MainWindow::showEvent(QShowEvent *event)
{

    QWidget::showEvent(event);
}

