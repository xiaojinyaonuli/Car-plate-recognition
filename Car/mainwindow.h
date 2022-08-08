#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"customerclass.h"
#include"recognitioncar.h"
#include"opaacount.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void initshadow();
    void initBiguttons();
    void btnsConnect();
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QPoint offest;
    BigButton *regcar;
    BigButton *account;
    RecognitionCar *Recogpage;
    OpaAcount *_opaacount;
    QPropertyAnimation *Recogpageani=nullptr;
    QPropertyAnimation *opaacountani=nullptr;
    const int Regispage_DURATION=1000;



protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void showEvent(QShowEvent *event);
};
#endif // MAINWINDOW_H
