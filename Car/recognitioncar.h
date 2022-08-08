/*****************************************
 * 作者: JS
 * 日期: 5.19
 * 类功能：车牌识别核心功能与界面
 * ***************************************/
#ifndef RECOGNITIONCAR_H
#define RECOGNITIONCAR_H
#include"customerclass.h"
#include <QWidget>
#include<QStringList>
#include<QList>
#include<QTimer>
namespace Ui {
class RecognitionCar;
}

class RecognitionCar : public QWidget
{
    Q_OBJECT

public:
    explicit RecognitionCar(QWidget *parent = nullptr);
    void initLabelwidget();
    void readfileimage_all();
    void initoperbtns();
    void btnsconnect();
    void operLabelWidget();
    void carpla(const QString & carimagepath,const int count);
    void addTWidget(const QString & car,const int count,const int result);
    void selectdata();
    void initshadow();
    void Close_On_Account();
    ~RecognitionCar();


private:
    QStringList ImgPath;
    CommonSmallButton* allselsect;
    CommonSmallButton *startbtn;
    CommonSmallButton *mainpage;
    CommonSmallButton *closepage;
    QTimer *timer=nullptr;
    QTimer *mysqltime=nullptr;
    DataThread *_cardata=nullptr;
    int Imgcount=0;
    QPoint offest;


private slots:

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void showEvent(QShowEvent *event);

private:
    Ui::RecognitionCar *ui;
signals:
    void carinfo(const QString& plate,const QString& intime,const QString& outtime,int money);


};

#endif // RECOGNITIONCAR_H
