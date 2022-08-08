/*****************************************
 * 作者: JS
 * 日期:  5.13
 * 类功能： 主界面自定义标题栏Titile
 * ***************************************/
#ifndef MAINTITLE_H
#define MAINTITLE_H

#include <QWidget>

namespace Ui {
class MainTitle;
}

class MainTitle : public QWidget
{
    Q_OBJECT

public:
    explicit MainTitle(QWidget *parent = nullptr);
    ~MainTitle();

private:
    Ui::MainTitle *ui;
};

#endif // MAINTITLE_H
