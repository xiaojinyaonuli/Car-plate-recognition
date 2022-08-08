/*****************************************
 * 作者: JS
 * 日期: 5.13
 * 类功能：注册界面类
 * ***************************************/
#include "registerpage.h"
#include "ui_registerpage.h"
#include"mainobject.h"
#include"opaacount.h"
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QLabel>
#include<QImage>
#include <QDesktopServices>
#include <QUrl>
#include<QDebug>
#include"mainwindow.h"
RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    this->setMouseTracking(true);
    ui->mywidget->setStyleSheet(QString("#mywidget{background-color:#080808;border-radius:15px;}"));
    timer=new QTimer();
    timer->setInterval(600);
    initshadow();
    InitAllcw();
    Commonbtnconnect();
}

RegisterPage::~RegisterPage()
{
    qDebug()<<"调用regisde"<<endl;
    delete ui;
}

void RegisterPage::initshadow()
{

    QGraphicsDropShadowEffect  *widget_shadow=new QGraphicsDropShadowEffect(this);
    widget_shadow->setOffset(0,0);

    widget_shadow->setColor(QColor("#080808"));

    widget_shadow->setBlurRadius(18);

    ui->mywidget->setGraphicsEffect(widget_shadow);
}

void RegisterPage::InitAllcw()
{
    QVBoxLayout *vlayout=new QVBoxLayout(ui->diswidget);
    ui->mywidget->setLayout(vlayout);
    QLabel *CarIcon=new QLabel(ui->diswidget);
    QImage imgicon;
    QPixmap *icon=new QPixmap(":/image/shibiecar.png");
    QWidget *bgwidget=new QWidget(ui->diswidget);

    QHBoxLayout *hlayout=new QHBoxLayout(bgwidget);
    bgwidget->setLayout(hlayout);
    CarIcon->setPixmap(*icon);
    CarIcon->setAlignment(Qt::AlignCenter);
    reg=new CommonSmallButton("注册","",0,false,5,bgwidget);
    log=new CommonSmallButton("登录","",0,false,5,bgwidget);
    log->setEnabled(false);
    reg->setMinimumSize(100,50);
    log->setMinimumSize(100,50);
    hlayout->addWidget(reg);
    hlayout->addWidget(log);
    hlayout->setSpacing(150);
    account=new InputText("账号:","input account",true,ui->diswidget);
    password=new InputText("密码:","",true,ui->diswidget);
    password->gettextinput()->setEchoMode(QLineEdit::Password);
    account->setMaximumSize(QSize(400,50));
    password->setMaximumSize(QSize(400,50));
    vlayout->setSpacing(15);
    vlayout->setContentsMargins(150,50,100,100);
    vlayout->addWidget(CarIcon);
    vlayout->addWidget(account);
    vlayout->addWidget(password);
    vlayout->addWidget(bgwidget);


    //线程
    monitor=new MyThread(NULL);

    //加载界面

}

void RegisterPage::Commonbtnconnect()
{
    timer->start();
    //注册按钮
    connect(reg,&CommonSmallButton::clicked,this,[=](){
         QDesktopServices::openUrl(QUrl(QString("http://118.195.179.135:9006")));
    });
    connect(timer,&QTimer::timeout,monitor,&MyThread::ThreadStart);
    //监视线程
    connect(account->gettextinput(),&QLineEdit::textEdited,monitor,&MyThread::GetAccount,Qt::UniqueConnection);
    connect(password->gettextinput(),&QLineEdit::textEdited,monitor,&MyThread::GetPassword,Qt::UniqueConnection);
    connect(monitor,&MyThread::APTrue,this,[=](bool is){log->setEnabled(is);});
    //登录按钮
    connect(log,&CommonSmallButton::clicked,this,[=](){
        if(nullptr==Regispage)
        {
            Regispage=new QPropertyAnimation(this,"windowOpacity");
            Regispage->setDuration(Regispage_DURATION);
            Regispage->setStartValue(1.0);
            Regispage->setEndValue(0);
        }
        Regispage->start();
        connect(Regispage,&QPropertyAnimation::finished,this,[=](){
            //monitor->ThreadStop();
            mainobj=new MainObject(nullptr); //用mainwindows  s   s.show 显示不出来
            this->hide();
            mainobj->setInit();

        });

//         MainWindow *s=new MainWindow(nullptr);
//         s->show();


     });

}

void RegisterPage::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QPoint off_temp;
        off_temp=event->globalPos()-offest;
        move(off_temp);
    }
    QWidget::mouseMoveEvent(event);

}

void RegisterPage::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        offest=event->globalPos()-pos();
    }
    QWidget::mousePressEvent(event);



}

void RegisterPage::mouseReleaseEvent(QMouseEvent *event)
{
   QWidget::mouseReleaseEvent(event);
}

void RegisterPage::showEvent(QShowEvent *event)
{

    QWidget::showEvent(event);
}
