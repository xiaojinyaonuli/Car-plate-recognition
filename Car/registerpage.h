/*****************************************
 * 作者: JS
 * 日期: 5.13
 * 类功能：注册界面类 注册功能
 * ***************************************/
#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QWidget>
#include"customerclass.h"
#include"opaacount.h"
#include"mainobject.h"
#include<QPropertyAnimation>
#include<QTimer>

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();
     CommonSmallButton *reg,*log;
     InputText *account,*password;
     MyThread *monitor=nullptr;
     MainObject *mainobj=nullptr;
     QTimer *timer;
private:
    QPoint offest;
    QPropertyAnimation *Regispage=nullptr;
    const int Regispage_DURATION=1000;
//    InputText *account;
//    InputText *password;
    //MainObject mainobj;
    void initshadow();//设置外边框阴影
    void InitAllcw();//初始化注册界面控件
    void Commonbtnconnect();

private:


protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void showEvent(QShowEvent *event);


private:
    Ui::RegisterPage *ui;
};

#endif // REGISTERPAGE_H
