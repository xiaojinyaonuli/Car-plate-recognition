/*****************************************
 * 作者: JS
 * 日期: 5.12
 * 类功能：自定义类 包含整个自定义重写的类
 * ***************************************/
#ifndef CUSTOMERCLASS_H
#define CUSTOMERCLASS_H
#include<QWidget>
#include<QGraphicsDropShadowEffect>
#include<QLineEdit>
#include<QLabel>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QPushButton>
#include<QSvgRenderer>
#include<QThread>
#include<QMutex>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlError>
#include <QSplashScreen>
#include <QPropertyAnimation>
/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：单例模式 设置颜色 方便调用
 * ***************************************/
class  Assistant
{

public:
    Assistant()
    {

    }
public:
    static void SetPushButtonQss(QPushButton *btn,
                          int radius,
                          const QString &bgnormallcolor,
                          const QString &bghovercolor,
                          const QString &pressedColor
                          );
    static void SetWidgetQss(QWidget *widget,
                             int radius,
                             const QString &background
                             );


};

class CustomPage : public QWidget
{
    Q_OBJECT
public:
    explicit CustomPage(bool isshadow,bool isroundrect, QWidget *parent = nullptr);
    void setNormallColor(const QString &color);

private:
    QColor normallcolor="#FF83FA";
    QGraphicsDropShadowEffect  *widget_shadow;
    bool IsShadow,IsRoundrect;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

signals:

};

class ActivityWidget: public CustomPage
{
    Q_OBJECT
public:
    explicit ActivityWidget(bool isshadow,bool isroundrect, QWidget *parent = nullptr);
    ~ActivityWidget();
private:
    QPoint offest;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void showEvent(QShowEvent *event);

    //virtual void paintEvent(QPaintEvent *event) override;
    virtual QSize sizeHint() const;

};



/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：自定义文本输入框类
 * ***************************************/

class InputText:public QWidget
{

    Q_OBJECT
public:
    InputText(const QString& Qlabelname,const QString &inputstring,bool Enable,QWidget *parent=nullptr);
    void EnterAnimation();
    void LeaveAnimation();
    void LinetextConnect();
    void SetResize(QWidget * parent);
    void SetTextLine(const QString &text);
    QString getText()const ;
    QLineEdit *gettextinput()const ;
private:
    QWidget *bgwidget;
    QLabel  *describe;
    QLineEdit *textinput;
    QWidget *indicator;
    QString firstinput;
    QColor EnterColor="#E0EEEE";
    QColor LeaveColor="#00000000";
    bool IsPressed;
    bool IsEdit;
    bool EnableEndit;
    QParallelAnimationGroup *EnterGroup,*LeaveGroup;
    QPropertyAnimation *Eindicatoranimation,*Etextinputanimation;
    QPropertyAnimation *Lindicatoranimation,*Ltextinputanimation;
//    MyThread *monitor=nullptr;


protected:
    void enterEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void Judge(bool change);
    void Etext(const QString &t);
public slots:
    void EditFinshed();
    void EditJudge();

};



/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：通用按钮类可支持旋转，按下缩放等
 * ***************************************/

class CommonSmallButton:public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle NOTIFY rotationAngleChanged)

public:
    CommonSmallButton(const QString &btnname,const QString& iconpath,
                      const qreal &wantrotateangle,const bool isrotate,
                      const int radius,
                      QWidget *parent=nullptr);
    void SetBgcolor(const QColor& color);
    void Setleavecolor(const QColor color);
    void setRotationAngle(qreal angle = 0);
    qreal rotationAngle() const {return rotateangle;}
private:
    QLabel *iconlabel;
    QPixmap *iconimage;
    QSvgRenderer *renderer;
    QString m_btnname;
    QColor LeaveColor="#F0FFFF";
    QColor BgColor;
    QColor EnterColor="#E0EEEE";
    QColor PressColor="#DEDEDE";
    qreal iconSizeRate = 0.8;
    QLabel *labeltext;
    int btnnametWidth=0;
    int btnnameHeight=0;
    qreal rotateangle;//旋转角
    bool ispressed;
    QPropertyAnimation *rotate;
    QPropertyAnimation *backrotate;
    bool isrotate_;
    int radius;
    qreal wantrotateangle_;
protected:
    void paintEvent(QPaintEvent *) override;
    void enterEvent(QEvent *event) override; //QEnterEvent 不行 解决：还不知道为什么
    void leaveEvent(QEvent* event)override;
    void  mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


public slots:
    void Slot_AnimationFinsh();
    void slot_paintline(QVariant a);
    void slot_Isrotatefinsh();
    void slot_animationfinsh();
signals:
    void rotationAngleChanged();
    void clicked();


};




/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：监视线程
 * ***************************************/
class MyThread:public QThread
{
    Q_OBJECT
private:
    bool isStop;
    QString account;
    QMutex mutex;
    QString FirstText;
    QString Password;
    QSqlDatabase db;
    QStringList ACCOUNT;
    QStringList PASSWD;
    void init_MySql();
    void MySqloperation(const QString & acc,const QString &pass);

public:
    MyThread(QObject *par);
    void ThreadStart();
    void ThreadStop(); 
protected:
    void run() override;
signals:
    void textinformation(const QString & str,bool cancreat);
    void APTrue(bool is);
 public slots:
     void GetPassword(const QString & password);
     void GetAccount(const QString & Account);

};


/*****************************************
 * 作者:
 * 日期:
 * 类功能：屏幕闪屏
 * ***************************************/
class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap &pixmap);
    ~SplashScreen();
    static SplashScreen *getInstance();

protected:
    void paintEvent (QPaintEvent *event);
public:
    void setStagePercent(const int &percent,const QString &message);
    void setStart(QWidget *widget, const QString &title,const QString &logoFile);
    void setFinish();
private:
    double m_percent;
    QWidget *m_mainWidget;
    QPixmap m_pixLogo;
    QString m_textLogo;
    QString m_message;
    static SplashScreen *m_instance;
    QPropertyAnimation *m_propertyAnimation;
private:
    const int ANIMATION_DURATION = 1500;

};

/*****************************************
 * 作者: JS
 * 日期:
 * 类功能：通用大按钮类
 * ***************************************/

class BigButton:public QWidget
{
    Q_OBJECT
public:
    explicit BigButton(const QString& iconpath,const QString& describe,QWidget *parent=nullptr);
    //~BigButton();
    void setscale(qreal scale);
    QString getbgEnterColor();
    QString getbgNormallColor();
    QString getbgstyle();
    QString getindiacatorstyle();
    QString getindiacatorNormallColor();
    QString getindiactorEnterColor();
    QString getbgPressedColor();
private:
    QWidget *bgwidget;
    QWidget *indicator;
    QPropertyAnimation *animation_indicator;
    QPropertyAnimation *animation_indicator_back;
    QPixmap *iconimage;
    QLabel *iconlabel;
    QLabel *textlabel;
    const QString bgnormallcolor="#F0FFFF";
    const QString bgentercolor="#E0EEEE";
    const QString bgpressedcolor="#E0E0E0";
    const QString bgstyle="border-radius:25px;";
    const QString indiactorNormallColor="#afafaf";
    const QString indiactorEnterColor="#4876FF";
    const QString indiacator_style="border-radius:3px;";
    bool ispressed;
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
    void clicked();

};
/*****************************************
 * 作者: JS
 * 日期:  5.22
 * 类功能： 本地数据库线程相关
 * ***************************************/
class DataThread:public QThread
{
    Q_OBJECT
private:
    bool isStop;
    QMutex mutex;
    QSqlDatabase db;
    QString _plate,_intime,_outtime;
    int _money;
    void init_mysql();
public:
    DataThread(QObject *par);
    void ThreadStart();
    void ThreadStop();
protected:
    void run() override;
signals:
    void isdone();

 public slots:
    void getcardata(const QString & plate,const QString & intime,const QString & outtime,int money);

};







#endif // CUSTOMERCLASS_H
