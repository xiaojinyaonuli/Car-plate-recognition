
/*****************************************
 * 作者: JS
 * 日期: 5.17
 * 类功能：轮播图功能
 * ***************************************/
#ifndef SLDERIMAGE_H
#define SLDERIMAGE_H

#include <QWidget>
#include<QRect>
#include<QTimer>
namespace Ui {
class SlderImage;
}

class SlderImage : public QWidget
{
    Q_OBJECT

public:
    explicit SlderImage(QWidget *parent = nullptr);
    ~SlderImage();
    void Time_Init_SliderImage();
    void Startanimation(QObject *target,QRect startRect,QRect endRect,bool isRaise);
    void ProceedAnimation();
    void StartTime();
private:
    Ui::SlderImage *ui;
    QRect r1,r2,r3,r4,r5;
    QTimer *time;
    int count=0;
public slots:
signals:
    void cl();



private slots:

};

#endif // SLDERIMAGE_H
