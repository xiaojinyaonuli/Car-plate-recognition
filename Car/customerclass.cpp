#include "customerclass.h"
#include<QResizeEvent>
#include<QPalette>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QPropertyAnimation>
#include<QGraphicsDropShadowEffect>
#include<QMutex>
#include<QVBoxLayout>
#include <QSplitter>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlError>
#include <QTimer>
#include <QApplication>
#include <QGuiApplication>
#define ASSISTANT


/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：单例模式 设置颜色 方便调用
 * ***************************************/
#ifdef ASSISTANT
void Assistant::SetPushButtonQss(QPushButton *btn,
                                 int radius,
                                 const QString &bgnormallcolor,
                                 const QString &bghovercolor,
                                 const QString &pressedColor)
{
    QStringList btnqss;

    btnqss.append(QString("QPushButton{border-radius:%1px;background-color:%2;}").arg(radius).arg(bgnormallcolor));

    QString qss=btnqss.join(" ");
    btn->setStyleSheet(qss);

}

void Assistant::SetWidgetQss(QWidget *widget, int radius, const QString &background)
{
    QStringList btnqss;

    btnqss.append(QString("QWidget{border-radius:%1px;background-color:%2;}").arg(radius).arg(background));

    QString qss=btnqss.join(" ");
    widget->setStyleSheet(qss);
}
#endif





/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：通用页面类 带阴影shadows，不支持无窗体，需要有父窗体
 * ***************************************/
CustomPage::CustomPage(bool isshadow,bool isroundrect,QWidget *parent) :
    IsShadow(isshadow),
    IsRoundrect(isroundrect),
    QWidget(parent)


{

    widget_shadow=new QGraphicsDropShadowEffect(this);
    widget_shadow->setOffset(0,0);

    widget_shadow->setColor(QColor("#080808"));

    widget_shadow->setBlurRadius(18);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->setMouseTracking(true);


}


void CustomPage::setNormallColor(const QString &color)
{
    this->normallcolor=color;

}


void CustomPage::resizeEvent(QResizeEvent *event)
{
    update();
}

void CustomPage::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);//重写绘画事件，绘制widget背景颜色，与圆角边框
    painter.setRenderHint(QPainter::Antialiasing);//反锯齿
    painter.setPen(Qt::NoPen);
    painter.setBrush(normallcolor);
    QRect rect=this->rect();
    rect.setWidth(rect.width()-1);
    rect.setHeight(rect.height()-1);
    if(IsRoundrect)
    {
        painter.drawRoundedRect(rect,15,15);

    }else
    {

        painter.drawRect(rect);

    }
    this->setGraphicsEffect(widget_shadow);

    QWidget::paintEvent(event);



}



/*****************************************
 * 作者: JS
 * 日期: 5.13
 * 类功能：活动窗口类 可支持拖动等操作
 * ***************************************/
ActivityWidget::ActivityWidget(bool isshadow, bool isroundrect, QWidget *parent)
    :CustomPage(isshadow,isroundrect,parent)
{


    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    this->setMouseTracking(true);


}

ActivityWidget::~ActivityWidget()
{

}

void ActivityWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QPoint off_temp;
        off_temp=event->globalPos()-offest;
        move(off_temp);
    }
    QWidget::mouseMoveEvent(event);

}

void ActivityWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        offest=event->globalPos()-pos();
    }
    QWidget::mousePressEvent(event);



}

void ActivityWidget::mouseReleaseEvent(QMouseEvent *event)
{
   QWidget::mouseReleaseEvent(event);
}

void ActivityWidget::showEvent(QShowEvent *event)
{

    QWidget::showEvent(event);
}

QSize ActivityWidget::sizeHint() const
{
    return QSize(500, 500);

}











/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：自定义文本输入框类
 * ***************************************/
InputText::InputText(const QString &Qlabelname,const QString &inputstring,bool Enable,QWidget *parent)
    :QWidget(parent),
    firstinput(inputstring),
    IsPressed(false),
    EnableEndit(Enable)

{
    QFont font=QFont("Consolas",12);
    describe=new QLabel(this);
    QFontMetrics fm(Qlabelname);
    qreal height = fm.lineSpacing();
    describe->setFont(font);
    describe->setText(Qlabelname);
    describe->setFixedHeight(height+10);
    describe->setStyleSheet("color:#1c1c1c;background-color:#00000000;");


    QFont textfont=QFont("Consolas",12);
    textinput=new QLineEdit(this);
    textinput->setFont(textfont);
    textinput->setText(inputstring);
    textinput->setReadOnly(true);
    textinput->setFixedHeight(height);
    textinput->setStyleSheet("color:#5c5c5c;background-color:#00000000;border-style:none;");


    bgwidget=new QWidget(this);
    bgwidget->resize(this->size());
    Assistant::SetWidgetQss(bgwidget,5,"#E0EEEE");
    bgwidget->lower();
    bgwidget->show();


    indicator=new QWidget(this);
    indicator->setFixedHeight(6);
    Assistant::SetWidgetQss(indicator,5,"#4876FF");
    indicator->show();

//    monitor=new MyThread(NULL);
    emit Etext(firstinput);
    this->setFixedHeight(describe->height()+10);

    LinetextConnect();

}

void InputText::EnterAnimation()
{

    textinput->setCursorPosition(textinput->text().length());
    textinput->setStyleSheet("color:#080808;background-color:#00000000;border-style:none;");
    EnterGroup=new QParallelAnimationGroup(this);
    Eindicatoranimation=new QPropertyAnimation(indicator,"geometry",this);
    Etextinputanimation=new QPropertyAnimation(textinput,"geometry",this);

    Eindicatoranimation->setDuration(600);
    Eindicatoranimation->setStartValue(indicator->geometry());
    Eindicatoranimation->setEasingCurve(QEasingCurve::InOutExpo);
    Eindicatoranimation->setEndValue(QRect(this->width()*0.3+2,this->height()-7,this->width()*0.7,6));

    Etextinputanimation->setDuration(600);
    Etextinputanimation->setStartValue(textinput->geometry());
    Etextinputanimation->setEasingCurve(QEasingCurve::InOutExpo);
    Etextinputanimation->setEndValue(QRect(this->width()*0.3,this->height()/2-textinput->height()/2,this->width()*0.7,textinput->height()));

    EnterGroup->addAnimation(Eindicatoranimation);
    EnterGroup->addAnimation(Etextinputanimation);
    EnterGroup->start();

}

void InputText::LeaveAnimation()
{
    textinput->setStyleSheet("color:#5c5c5c;background-color:#00000000;border-style:none;");
    textinput->setCursorPosition(0);
    LeaveGroup=new QParallelAnimationGroup(this);
    Lindicatoranimation=new QPropertyAnimation(indicator,"geometry",this);
    Ltextinputanimation=new QPropertyAnimation(textinput,"geometry",this);

    Lindicatoranimation->setDuration(600);
    Lindicatoranimation->setStartValue(indicator->geometry());
    Lindicatoranimation->setEasingCurve(QEasingCurve::InOutExpo);
    Lindicatoranimation->setEndValue(QRect(this->width(),this->height()-7,this->width()*0.1,6));

    int width = QFontMetrics(textinput->font()).size(Qt::TextSingleLine, textinput->text()).width()+1;

    Ltextinputanimation->setDuration(600);
    Ltextinputanimation->setStartValue(textinput->geometry());
    Ltextinputanimation->setEasingCurve(QEasingCurve::InOutExpo);
    width>this->width()*0.7?Ltextinputanimation->setEndValue(QRect(this->width()*0.3+30,this->height()/2-textinput->height()/2,this->width()*0.7,textinput->height()))
                          :Ltextinputanimation->setEndValue(QRect(this->width()-width,this->height()/2-textinput->height()/2,this->width()*0.5,textinput->height()));

    LeaveGroup->addAnimation(Lindicatoranimation);
    LeaveGroup->addAnimation(Ltextinputanimation);
    LeaveGroup->start();

}

void InputText::LinetextConnect()
{

    connect(textinput,&QLineEdit::editingFinished,this,&InputText::EditFinshed);



}

void InputText::SetResize(QWidget *parent)
{
    //

}

void InputText::SetTextLine(const QString &text)
{
    textinput->setText(text);

}

QString InputText::getText() const
{
    return textinput->text();

}

QLineEdit *InputText::gettextinput() const
{
    return this->textinput;

}

//void InputText::setLinetext(const QString &text)
//{
//    textinput->setText(text);

//}

void InputText::enterEvent(QEvent *event)
{

    Assistant::SetWidgetQss(bgwidget,5,"#E0EEEE");



}

void InputText::resizeEvent(QResizeEvent *event)
{
    int width = QFontMetrics(textinput->font()).size(Qt::TextSingleLine, textinput->text()).width()+1;
    describe->move(5,this->height()/2-describe->height()/2);
    width>this->width()*0.7?textinput->resize(this->width()*0.7,textinput->height())
                          : textinput->resize(this->width()*0.4,textinput->height());
    width>this->width()*0.7?textinput->move(this->width()*0.3+30,this->height()/2-textinput->height()/2)
                          :textinput->move(this->width()-width,this->height()/2-textinput->height()/2);

    indicator->resize(this->width()*0.1,indicator->height());
    indicator->move(this->width(),this->height()-7);
    Assistant::SetWidgetQss(indicator,10,"#4876FF");
    bgwidget->resize(this->size());

}

void InputText::leaveEvent(QEvent *event)
{
    IsPressed=false;
    if(!IsEdit)
    {
        Assistant::SetWidgetQss(bgwidget,5,"#E0EEEE");
    }

}

void InputText::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        IsPressed=true;

    }

}

void InputText::mouseReleaseEvent(QMouseEvent *event)
{
    if(IsPressed&&EnableEndit)
    {
       EnterAnimation();
       IsPressed=false;
       textinput->setReadOnly(false);
       textinput->raise();
       textinput->setFocus();

//       qDebug()<<"当前线程"<<(int)GetCurrentThread()<<endl;
       IsEdit=true;
    }



}

void InputText::mouseMoveEvent(QMouseEvent *event)
{
    if(IsPressed)
    {
        event->accept();
    }

}

void InputText::EditFinshed()
{
    LeaveAnimation();
    IsEdit=false;
    textinput->setReadOnly(true);


}

void InputText::EditJudge()
{
    if(textinput->text()!=firstinput)
    {
        emit Judge(true);
    }

}




/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：通用按钮类可支持旋转，按下缩放等
 * ***************************************/



CommonSmallButton::CommonSmallButton(const QString &btnname,
                                     const QString &iconpath,
                                     const qreal &wantrotateangle,
                                     const bool isrotate,
                                     const int radius,
                                     QWidget *parent):QPushButton(parent),
                                     m_btnname(btnname),
                                     BgColor(LeaveColor),
                                     rotateangle(0),
                                     ispressed(false),
                                     isrotate_(isrotate),
                                     radius(radius),
                                     wantrotateangle_(wantrotateangle)
{


     renderer=new QSvgRenderer();
     renderer->load(iconpath);
     QSize size=renderer->defaultSize();
     this->setText(btnname);
     iconlabel=new QLabel(this);
     iconimage=new QPixmap(size);
     iconimage->fill(Qt::transparent);//设置背景透明
     QPainter painter(iconimage);
     painter.setRenderHints(QPainter::Antialiasing);
     renderer->render(&painter);
     QFont font= QFont("Consolas",12,70);
     this->setFont(font);
     QFontMetrics fm(font);
     QRect rec = fm.boundingRect(m_btnname);

     //字符串所占的像素宽度,高度
     btnnametWidth = rec.width();
     btnnameHeight= fm.lineSpacing();
     rotate=new QPropertyAnimation(this,"rotationAngle");

     connect(rotate,SIGNAL(valueChanged(QVariant)),this,SLOT(slot_paintline(QVariant))
             );
     //connect(rotate,SIGNAL(finished()),this,SLOT(Slot_AnimationFinsh()));


}

void CommonSmallButton::SetBgcolor(const QColor &color)
{
    BgColor=color;
}

void CommonSmallButton::Setleavecolor(const QColor color)
{
    this->LeaveColor=color;
}

void CommonSmallButton::setRotationAngle(qreal angle)
{
    rotateangle = angle;update();
}

void CommonSmallButton::paintEvent(QPaintEvent *)
{
    resize(height(), height());
    QPainter painterbg(this);
    painterbg.save();
    painterbg.setPen(Qt::NoPen);
    painterbg.setBrush(BgColor);
    painterbg.setRenderHint(QPainter::Antialiasing,true);
    painterbg.drawRoundedRect(this->rect(),radius,radius);
    painterbg.restore();


    QPainter p(this);
    p.save();
    p.setRenderHint(QPainter::Antialiasing);
    p.translate(width()/2,height()/2);
    p.rotate(rotateangle);
    p.translate(-width()/2,-height()/2);//将原点复位  qt坐标轴向上是- 向左是-
    int w = iconSizeRate * width();
    int h = iconSizeRate * height();
    p.drawPixmap(width() / 2 - w / 2, height() / 2 - h / 2, w, h, *iconimage);
    p.drawText(width()/2-btnnametWidth/2,height()/2+btnnameHeight/2-5,m_btnname);

    p.restore();
}

void CommonSmallButton::enterEvent(QEvent *event)
{
    if(this->isEnabled())
    {
        SetBgcolor(EnterColor);
        update();
    }



}

void CommonSmallButton::leaveEvent(QEvent *event)
{
    SetBgcolor(LeaveColor);
    update();
}

void CommonSmallButton::mousePressEvent(QMouseEvent *event)
{

    iconSizeRate-=0.1;
    ispressed=true;
    if(ispressed)
    {
        SetBgcolor(PressColor);
    }
    setFocus();

   if(isrotate_&&ispressed)
   {
       rotate=new QPropertyAnimation(this,"rotationAngle");
       rotate->setStartValue(0);
       rotate->setDuration(800);
       rotate->setEasingCurve(QEasingCurve::OutBack);
       rotate->setEndValue(wantrotateangle_);
       rotate->start();
       connect(rotate,SIGNAL(finished()),this,SLOT(Slot_AnimationFinsh()));
   }
   if(!isrotate_&&ispressed)
   {

       emit clicked();
   }

}

void CommonSmallButton::mouseMoveEvent(QMouseEvent *event)
{
    if(ispressed)
    {
        event->accept();
    }
}

void CommonSmallButton::mouseReleaseEvent(QMouseEvent *event)
{

    iconSizeRate+=0.1;
    ispressed=false;
    if(!ispressed)
    {
        SetBgcolor(LeaveColor);
    }

}

void CommonSmallButton::resizeEvent(QResizeEvent *event)
{
    update();
}

void CommonSmallButton::Slot_AnimationFinsh()
{
    emit clicked();

}

void CommonSmallButton::slot_paintline(QVariant a)
{

}

void CommonSmallButton::slot_Isrotatefinsh()
{
    ispressed=true;


}

void CommonSmallButton::slot_animationfinsh()
{
    this->isrotate_=false;

}






/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：监视线程
 * ***************************************/

void MyThread::init_MySql()
{
//    db= QSqlDatabase::addDatabase("QMYSQL");         //此处为连接云服务器数据库操作，如果你配置好了云服务器上的数据库，请你将此处代码注释解除，不懂的可以查询百度
//    db.setHostName("xxx.xxx.xxx.xxx");
//    db.setPort(3306);
//    db.setDatabaseName("yourdb");
//    db.setUserName("root");
//    db.setPassword("xxxxxxxxxxxx");//你的密码
//    (!db.open())?qDebug()<<db.lastError().text():qDebug() << "open";
//    QSqlQuery query(db);
//    query.exec("select *from user"); //查询user表
//    while (query.next()) {
//        ACCOUNT<<query.value(0).toString();
//        PASSWD<<query.value(1).toString();

//    }

}

void MyThread::MySqloperation(const QString & acc,const QString &pass)
{
//    foreach(auto ACC ,ACCOUNT){
//        if(ACC==acc){
//            foreach (auto PASS, PASSWD) {
//                if(PASS==pass){emit APTrue(true);}
//            }
//        }else continue;               // 此处为循环对比你在云服务器中已经在注册界面注册的账号与密码是否和你目前正在输入框输入的一样
//    }                                 // 就是说 你已经注册的账号  和你目前输入的账号是否一致，一致就发送true的信号，让登录按钮变的可用


    emit APTrue(true);   //这里是方便进入，如果你已经布置好了云服务器等配置，请你将此行注释，并将上处注释取消!!!!!!!

}


MyThread::MyThread(QObject *par):QThread(par)
{

    isStop=false;


}

void MyThread::ThreadStart()
{


    if(!this->isRunning())
    {
        init_MySql();
        this->start();

    }
    else
    {

        return;
    }



}


void MyThread::ThreadStop()
{
    QMutexLocker loker(&mutex);
    isStop=true;
}

void MyThread::run()
{
    isStop=false;
    while(!isStop)
    {
//        qDebug()<<"子线程在运行"<<(int)currentThread()<<endl;

        mutex.lock();
        MySqloperation(account,Password);
        //qDebug()<<account<<"****"<<Password<<endl;
        mutex.unlock();

        msleep(500);
    }


}



void MyThread::GetPassword(const QString &password)
{
    Password =password;

}

void MyThread::GetAccount(const QString &Account)
{

    account=Account;
}





/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：闪屏
 * ***************************************/



SplashScreen *SplashScreen::m_instance = nullptr;

// 构造函数
SplashScreen::SplashScreen(const QPixmap &pixmap)
    : QSplashScreen(pixmap)
    , m_percent(0)
    , m_mainWidget(nullptr)
    , m_propertyAnimation(nullptr)
{
}

// 析构函数
SplashScreen::~SplashScreen()
{

}

// 单例模式
SplashScreen *SplashScreen::getInstance()
{
    if(nullptr == m_instance)
    {
        m_instance = new SplashScreen(QPixmap(":/image/fengmian.png"));
    }
    return m_instance;
}

// 绘制事件
void SplashScreen::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int OFFSET_VALUE = 70;
    const int SLIDER_HEIGHT = 10;
    const int BORDER_X_RADIUS = 8;
    const int BORDER_Y_RADIUS = 4;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font(QString("微软雅黑"));
    QPen painterPen;
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    QBrush brush(QColor(100, 100, 100 ,255));
    painter.setBrush(brush);
    painter.drawRoundedRect(OFFSET_VALUE, this->height() - OFFSET_VALUE
                            ,(this->width()- OFFSET_VALUE * 2)
                            ,BORDER_X_RADIUS,BORDER_Y_RADIUS,SLIDER_HEIGHT);

    // 绘制消息文本
    {
        font.setPixelSize(16);
        font.setBold(true);
        painter.setFont(font);
        painterPen.setColor(Qt::yellow);
        painter.setPen(painterPen);
        painter.drawText(0, this->height()- OFFSET_VALUE * 2, this->width(), OFFSET_VALUE, Qt::AlignCenter, m_message);
    }

    // 绘制进度条
    {
        painterPen.setColor(Qt::white);
        painter.setPen(painterPen);
        if(m_percent != 0)
        {
            QBrush brush(QColor(150, 230, 100 ,255));
            painter.setBrush(brush);
            painter.drawRoundedRect(OFFSET_VALUE, this->height() - OFFSET_VALUE
                                    , (this->rect().width()- OFFSET_VALUE * 2) * m_percent / 100
                                    , BORDER_X_RADIUS,BORDER_Y_RADIUS,SLIDER_HEIGHT);
        }
    }

    // 绘制进度文本
    {
        font.setPixelSize(14);
        font.setBold(false);
        painter.setFont(font);
        painterPen.setColor(Qt::white);
        painter.setPen(painterPen);
        QString drawText = QString::number(m_percent,'f',0) + QString("%");
        painter.drawText(0, this->height() - OFFSET_VALUE, this->width(), OFFSET_VALUE, Qt::AlignCenter, drawText);
        painter.end();
    }

    // 绘制圆角窗体
    {
        QPainterPath painterPathPath;
        QRectF rect = QRectF(0, 0, this->width(), this->height());
        painterPathPath.addRoundRect(rect, BORDER_X_RADIUS, BORDER_X_RADIUS);
        QPolygon polygon= painterPathPath.toFillPolygon().toPolygon();
        QRegion region(polygon);
        this->setMask(region);
    }
}



// 设置进度
void SplashScreen::setStagePercent(const int &percent, const QString &message)
{
    if(this->isHidden())
    {
        this->show();
    }
    if(!this->isActiveWindow())
    {
        this->activateWindow();
        this->raise();
    }
    m_message = message;

    while (m_percent < percent)
    {
        m_percent = m_percent + 0.01;
        qApp->processEvents();
        this->repaint();
    }
}

// 开始
void SplashScreen::setStart(QWidget *widget, const QString &title, const QString &logoFile)
{
    if (nullptr != widget)
    {
        m_mainWidget = widget;
        m_pixLogo = QPixmap(logoFile);
        m_textLogo = title;
        m_mainWidget->setWindowOpacity(0.0);
        if (nullptr == m_propertyAnimation)
        {
            m_propertyAnimation = new QPropertyAnimation(m_mainWidget, "windowOpacity");
            m_propertyAnimation->setDuration(ANIMATION_DURATION);
            m_propertyAnimation->setStartValue(0.0);
            m_propertyAnimation->setEndValue(1.0);
        }
    }
}

// 结束
void SplashScreen::setFinish()
{
    this->close();
    if (nullptr != m_mainWidget)
    {
        m_mainWidget->activateWindow();
        m_mainWidget->raise();
    }
    if (nullptr != m_propertyAnimation)
    {
        m_propertyAnimation->start();
    }

}




/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：通用大按钮类
 * ***************************************/
BigButton::BigButton(const QString &iconpath, const QString &describe, QWidget *parent)
 :QWidget(parent)
 ,ispressed(false)
{


    iconimage=new QPixmap(iconpath);

    iconlabel=new QLabel(this);

    iconlabel->setPixmap(*iconimage);
    iconlabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    iconlabel->setMinimumSize(50,50);
    iconlabel->setAlignment(Qt::AlignCenter);


    QFont font_= QFont("Consolas",13,75);
    textlabel=new QLabel(this);
    textlabel->setFont(font_);
    textlabel->setText(describe);
    textlabel->setWordWrap(true);
    textlabel->setMinimumHeight(50);
    textlabel->setAlignment(Qt::AlignCenter);

    //#04000000

    indicator=new QWidget(this);
    indicator->resize(50,10);
    indicator->move(this->width()-3,this->height()-20);
    indicator->setStyleSheet(getindiacatorstyle()+QString("background-color:%1").arg(getindiacatorNormallColor()));


    bgwidget=new QWidget(this);

    bgwidget->resize(this->size());//#EE7AE9

    bgwidget->setStyleSheet(getbgstyle()+QString("background-color:%1").arg(getbgNormallColor()));

    bgwidget->lower();

    bgwidget->move(iconlabel->pos());

    bgwidget->show();

    qDebug()<<bgwidget->pos()<<endl;


    QVBoxLayout *layout=new QVBoxLayout(this);

    this->setLayout(layout);

    layout->setContentsMargins(15,35,10,35);

    layout->setSpacing(0);

    layout->addWidget(iconlabel);

    layout->addWidget(textlabel);

    layout->setAlignment(Qt::AlignCenter);

    this->setMinimumHeight(130);




}
///
/// \brief BigButton::setscale
/// \param scale
///
void BigButton::setscale(qreal scale)
{
    iconimage=new QPixmap(iconimage->scaled( iconimage->size()*scale,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    iconlabel->setPixmap(*iconimage);
}

QString BigButton::getbgEnterColor()
{
    return  this->bgentercolor;
}

QString BigButton::getbgNormallColor()
{
    return this->bgnormallcolor;
}

QString BigButton::getbgstyle()
{
    return this->bgstyle;
}

QString BigButton::getindiacatorstyle()
{
    return this->indiacator_style;
}

QString BigButton::getindiacatorNormallColor()
{
    return this->indiactorNormallColor;
}

QString BigButton::getindiactorEnterColor()
{
    return this->indiactorEnterColor;
}

QString BigButton::getbgPressedColor()
{
    return this->bgpressedcolor;
}


void BigButton::enterEvent(QEvent *event)
{
     bgwidget->setStyleSheet(getbgstyle()
                             +QString("background-color:%1").arg(getbgEnterColor()));
     indicator->setStyleSheet(getindiacatorstyle()
                              +QString("background-color:%1").arg(getindiactorEnterColor()));
     animation_indicator=new QPropertyAnimation(indicator,"geometry",this);
     animation_indicator->setDuration(150);
     animation_indicator->setStartValue(indicator->geometry());
     animation_indicator->setEndValue(QRect(this->width()*0.2,this->height()-20,this->width()*0.6,10));
     animation_indicator->setEasingCurve(QEasingCurve::OutBack);
     animation_indicator->start();


}

void BigButton::leaveEvent(QEvent *event)
{
     bgwidget->setStyleSheet(getbgstyle()
                             +QString("background-color:%1").arg(getbgNormallColor()));
     animation_indicator_back=new QPropertyAnimation(indicator,"geometry",this);
     animation_indicator_back->setDuration(150);
     animation_indicator_back->setStartValue(indicator->geometry());
     animation_indicator_back->setEndValue(QRect(this->width()*0.47,this->height()-20,this->width()*0.1,10));
     animation_indicator_back->setEasingCurve(QEasingCurve::OutBack);
     animation_indicator_back->start();

     indicator->setStyleSheet(getindiacatorstyle()
                              +QString("background-color:%1").arg(getindiacatorNormallColor()));



}

void BigButton::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"大小发生改变"<< event->size()<<endl;//布局会默认改变widget的大小尽管你刚开始指定了其大小与位置，通过resizeevent事件去判断是否进行了改变

    //bgwidget->resize(this->size());
    bgwidget->setFixedSize(this->size());

    indicator->resize(this->width()*0.1,10);
    indicator->move(this->width()*0.46,this->height()-20);

}

void BigButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"按下"<<endl;
        bgwidget->setStyleSheet(getbgstyle()+QString("background-color:%1").arg(getbgPressedColor()));
        ispressed=true;
        emit clicked();
    }

}

void BigButton::mouseMoveEvent(QMouseEvent *event)
{
    if(ispressed)
    {
        event->accept();//接受bgwidget鼠标移动事件，避免点击bigbutton会出现主界面移动问题
                        //原理：事件的传递顺序 在此接受此事件，便不会传递给bigbutton的父部件
    }
}

void BigButton::mouseReleaseEvent(QMouseEvent *event)
{
    ispressed=false;
    bgwidget->setStyleSheet(getbgstyle()+QString("background-color:%1").arg(getbgEnterColor()));
}



/*****************************************
 * 作者: JS
 * 日期:  5.22
 * 类功能： 本地数据库线程相关
 * ***************************************/

void DataThread::init_mysql()
{

    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("car");
    db.setUserName("root");
    db.setPassword("1314jinshen");
    (!db.open())?qDebug()<<db.lastError().text():qDebug() << "open";
    if(db.open())
    {
        qDebug()<<"sadasd"<<_plate<<endl;
        QSqlQuery query;
        query.prepare("INSERT INTO data (plate, intime, outtime, money ) "
                              "VALUES (:plate, :intime, :outtime, :money)");

        query.bindValue(0, _plate);
        query.bindValue(1, _intime);
        query.bindValue(2, _outtime);
        query.bindValue(3, _money);
        query.exec();
    }


    qDebug()<<"插入"<<endl;
}

DataThread::DataThread(QObject *par)
{
    isStop=false;
}

void DataThread::ThreadStart()
{
    if(!this->isRunning())
    {
        init_mysql();
        this->start();


    }
    else
    {

        return;
    }
}

void DataThread::ThreadStop()
{
    QMutexLocker loker(&mutex);
    isStop=true;
}

void DataThread::run()
{
    isStop=false;
    while(!isStop)
    {
        qDebug()<<"在运行"<<endl;
       mutex.lock();
       db.close();
       qDebug()<<"bu在运行"<<endl;
       emit isdone();
       qDebug()<<"bu在运行2"<<endl;
       mutex.unlock();
    }
}

void DataThread::getcardata(const QString &plate, const QString &intime, const QString &outtime, int money)
{
    _plate=plate;
    _intime=intime;
    _outtime=outtime;
    _money=money;
}
