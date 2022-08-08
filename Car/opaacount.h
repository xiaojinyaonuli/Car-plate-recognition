/*****************************************
 * 作者: JS
 * 日期: 5.22
 * 类功能：显示账单类
 * ***************************************/

#ifndef OPAACOUNT_H
#define OPAACOUNT_H

#include <QWidget>
#include<QSqlDatabase>
namespace Ui {
class OpaAcount;
}

class OpaAcount : public QWidget
{
    Q_OBJECT

public:
    explicit OpaAcount(QWidget *parent = nullptr);
    void  initLabelwidget();
    void opramysql_addwidget();
    QStringList Plate,Intime,Outtime,Money;
//    QList<int> Money;
    ~OpaAcount();

private:
    Ui::OpaAcount *ui;
    QSqlDatabase db;
};

#endif // OPAACOUNT_H
