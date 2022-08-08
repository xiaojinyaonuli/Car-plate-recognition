
#include "opaacount.h"
#include "ui_opaacount.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
/*****************************************
 * 作者: JS
 * 日期: 5.22
 * 类功能：显示账单类
 * ***************************************/
OpaAcount::OpaAcount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpaAcount)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("账单结算"));
    this->setWindowIcon(QIcon(":/image/icon.png"));
    initLabelwidget();
    opramysql_addwidget();
}

void OpaAcount::initLabelwidget()
{
    ui->tab->setStyleSheet(     "QTableView,QTableWidget {"
                                "selection-background-color:#44c767;"
                                "background-color:white;"     /*整个表格的背景色，这里为白色*/
                                "border:1px solid #E0DDDC;"   /*边框为1像素，灰色*/
                                "gridline-color:lightgray;}"   /*这个是表格的格子线的颜色，为亮灰*/

                            /*这里是表格表头样式*/
                            "QHeaderView::section {"
                                "background-color:#79CDCD;"     /*背景色 白色*/
                                "border:0px solid #6495ED; "  /*先把边框宽度设为0，即隐藏所有表头边框*/
                                "border-bottom:3px solid #44c767;"/*然后只显示下边框，因为上边框和左右边框是整个Table的边框，都显示会有2px的边框宽度*/
                                "height:30px; font-size:18px;}"               /*表头高度*/

                           );

    //设置列数和列宽
    int width = 1920;
    ui->tab->setColumnCount(4);
    ui->tab->setColumnWidth(0, width * 0.10);
    ui->tab->setColumnWidth(1, width * 0.10);
    ui->tab->setColumnWidth(2, width * 0.10);
    ui->tab->setColumnWidth(3, width * 0.10);
    ui->tab->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "车辆信息" << "入库时间" << "出库时间" << "金额";
    ui->tab->setHorizontalHeaderLabels(headText);
    ui->tab->setFrameShape(QFrame::NoFrame);
    ui->tab->setShowGrid(false);
    ui->tab->verticalHeader()->setHidden(true);
    ui->tab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tab->setAlternatingRowColors(true);
    ui->tab->verticalHeader()->setVisible(false);
    ui->tab->horizontalHeader()->setStretchLastSection(true);
}

void OpaAcount::opramysql_addwidget()
{
    qDebug()<<"数据库导入开始"<<endl;
    db= QSqlDatabase::addDatabase("QMYSQL","haha");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("car");
    db.setUserName("root");
    db.setPassword("1314jinshen");
    (!db.open())?qDebug()<<db.lastError().text():qDebug() << "open";
    QSqlQuery query(db);
    qDebug()<<"数据库导入开始2"<<endl;
    query.exec("select *from data"); //查询data表
    qDebug()<<"数据库导入开始3"<<endl;
    while (query.next()) {
        Plate<<query.value(0).toString();
        Intime<<query.value(1).toString();
        Outtime<<query.value(2).toString();
        Money<<query.value(3).toString();
        qDebug()<<"数据库导入开始4"<<endl;

    }

    ui->tab->setRowCount(Plate.size());

    for(int i=0;i<Plate.size();++i)
    {

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(Plate[i]);
        QTableWidgetItem *itemplate = new QTableWidgetItem(Intime[i]);

        QTableWidgetItem *itemTime = new QTableWidgetItem(Outtime[i]);
        QTableWidgetItem *itemopre = new QTableWidgetItem(Money[i]);
        ui->tab->setItem(i, 0, itemDeviceID);
        ui->tab->setItem(i, 1, itemplate);
        ui->tab->setItem(i, 2, itemTime);
        ui->tab->setItem(i, 3, itemopre);
        ui->tab->item(i,0)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(i,1)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(i,2)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(i,3)->setTextAlignment(Qt::AlignCenter);

    }

    int count=0;
    for(int j=0;j<Money.size();++j)
    {
        count+=Money[j].toInt();
    }
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setFont(QFont("微软雅黑",18));

    ui->label->setText("月度总收取费用账单为 :" +QString("%1元").arg(count));




}

OpaAcount::~OpaAcount()
{
    delete ui;
}
