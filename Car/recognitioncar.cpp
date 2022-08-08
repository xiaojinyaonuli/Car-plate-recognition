/*****************************************
 * 作者: JS
 * 日期: 5.19
 * 类功能：车牌识别核心功能与界面
 * ***************************************/
#include "recognitioncar.h"
#include "ui_recognitioncar.h"
#include"customerclass.h"
#include "easypr.h"
#include "easypr/util/switch.hpp"
#include"test/plate.hpp"
#include<QDateTime>
#include<QFileDialog>
#include<QDebug>
#include<QThread>
#include<QMouseEvent>
#include<QMessageBox>
#include<QDateTime>

//using namespace easypr;
//using namespace cv;

RecognitionCar::RecognitionCar(QWidget *parent) :
    QWidget(parent),
    allselsect(nullptr),
    startbtn(nullptr),
    mainpage(nullptr),
    closepage(nullptr),
    ui(new Ui::RecognitionCar)

{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowTitle(tr("车牌识别"));
    this->setWindowIcon(QIcon(":/image/icon.png"));
    //setAttribute(Qt::WA_DeleteOnClose);
    ui->widget->setStyleSheet(QString("#widget{background-color:#F0FFFF;border-radius:0px;}"));
//    ui->recar->setStyleSheet(QString("#recar{background-color:#F0FFFF;border-radius:15px;}"));

    ui->carimage->setStyleSheet("QLabel{border-radius:5px;border:5px solid black;}");
    ui->oper->setStyleSheet("#oper{background-color:#F0FFFF;}");
    timer=new QTimer();
    timer->setInterval(900);
    mysqltime=new QTimer();
    mysqltime->setInterval(1500);
    _cardata=new DataThread(NULL);
    initshadow();
    initLabelwidget();
    initoperbtns();
    btnsconnect();

}

void RecognitionCar::initLabelwidget()
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
    ui->tab->setColumnCount(5);
    ui->tab->setColumnWidth(0, width * 0.10);
    ui->tab->setColumnWidth(1, width * 0.10);
    ui->tab->setColumnWidth(2, width * 0.10);
    ui->tab->setColumnWidth(3, width * 0.10);
    ui->tab->setColumnWidth(4, width * 0.10);
    ui->tab->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "车辆编号" << "车牌号" << "是否识别" << "入库时间" << "操作";
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

//    ui->carimage->setPixmap(QString("D:/EasyPR-master/EasyPR-master/resources/image/plate_detect.jpg"));
//    ui->carimage->setScaledContents(true);

}

void RecognitionCar::readfileimage_all()
{
    QString mFolderPath=QFileDialog::getExistingDirectory(this,tr("Open Directory"),"D:\\");
    QStringList ImgNames;
    qDebug()<<mFolderPath<<endl;
    if (mFolderPath.isEmpty()) return;
    // 获取所有文件名
        QDir dir(mFolderPath);
        mFolderPath = dir.fromNativeSeparators(mFolderPath);//  "\\"转为"/"
        if (!dir.exists()) ImgNames = QStringList("");
        dir.setFilter(QDir::Files);
        dir.setSorting(QDir::Name);
        dir.setNameFilters(QString("*.png;*.jpg").split(";"));
            ImgNames = dir.entryList();

        for (int i = 0; i < ImgNames.size(); ++i)
            {
                //qDebug() << "entryList: " << i << "-" << mFolderPath + "/" +ImgNames[i];
                ImgPath<<mFolderPath + "/" +ImgNames[i];
            }
//        for(int i = 0; i < ImgPath.size(); ++i)
//        {
//            qDebug() << QString("imgpath: %1:").arg(i) << ImgPath[i];
//        }
}

void RecognitionCar::initoperbtns()
{
    QVBoxLayout *vlayout=new QVBoxLayout(ui->oper);
    vlayout->setAlignment(Qt::AlignCenter);
    allselsect=new CommonSmallButton("",":/image/open.svg",360,true,15,ui->oper);
    startbtn=new CommonSmallButton("",":/image/start.svg",360,true,15,ui->oper);
    mainpage=new CommonSmallButton("",":/image/mainpage.svg",360,false,15,ui->oper);
    closepage=new CommonSmallButton("",":/image/close_.svg",360,false,15,ui->oper);
    allselsect->setMaximumSize(50,50);
    allselsect->setMinimumSize(50,50);
    startbtn->setMaximumSize(50,50);
    startbtn->setMinimumSize(50,50);
    mainpage->setMaximumSize(50,50);
    mainpage->setMinimumSize(50,50);
    closepage->setMaximumSize(50,50);
    closepage->setMinimumSize(50,50);
    ui->oper->setLayout(vlayout);
    vlayout->addWidget(allselsect);
    vlayout->addWidget(startbtn);
    vlayout->addWidget(mainpage);
    vlayout->addWidget(closepage);



}

void RecognitionCar::btnsconnect()
{


    connect(allselsect,&CommonSmallButton::clicked,this,&RecognitionCar::readfileimage_all);
    connect(startbtn,&CommonSmallButton::clicked,this,&RecognitionCar::operLabelWidget);
    connect(closepage,&CommonSmallButton::clicked,this,[=](){this->close();});
    connect(timer,&QTimer::timeout,this,[=](){
        if(Imgcount<ImgPath.size())
        {
            ui->tab->setRowHeight(Imgcount, 24);
            ui->carimage->setPixmap(QString("%1").arg(ImgPath[Imgcount]));
            carpla(ImgPath[Imgcount],Imgcount);
            Imgcount++;
        }else {timer->stop();Imgcount=0;}

    });
    //connect(ui->tab,&QTableWidget::cellClicked,this,&RecognitionCar::selectdata);
    connect(mainpage,&CommonSmallButton::clicked,this,[=](){
        this->hide();
    });
    connect(mysqltime,&QTimer::timeout,_cardata,&DataThread::ThreadStart);
    connect(_cardata,&DataThread::isdone,this,[=](){
        qDebug()<<"发射中介信号"<<endl;
        mysqltime->stop();
        _cardata->ThreadStop();
    });
}

void RecognitionCar::operLabelWidget()
{
    int count=ImgPath.size();
    ui->carimage->setScaledContents(true);
    ui->tab->setRowCount(count);
    timer->start();
}

void RecognitionCar::carpla(const QString & carimagepath,const int count)
{
        easypr::CPlateRecognize pr;
        pr.setDetectType(easypr::PR_DETECT_CMSER|easypr::PR_DETECT_COLOR);
        vector<easypr::CPlate> plateVec;
        cv::Mat src=imread(carimagepath.toLocal8Bit().data());
        pr.setResultShow(false);
        int result=pr.plateRecognize(src,plateVec);
        qDebug()<<result;
        pr.getDetectShow();
        //qDebug()<<"******"<<plateVec.size()<<endl;
        easypr::CPlate plate;
        if(plateVec.size()<=0)
        {
            result=-1;
        }else{
             plate=plateVec.at(0);
        }
        string license=plate.getPlateStr();
        QString lince1=QString::fromLocal8Bit(license.c_str());
        qDebug()<<"识别出的车牌为:"<<lince1;
        addTWidget(lince1,count,result);

}

void RecognitionCar::addTWidget(const QString & car,const int count,const int result)
{

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(count + 1));
        QTableWidgetItem *itemplate = new QTableWidgetItem(car);
        QTableWidgetItem *itemjudge;
        if(result<0)
        {
            itemjudge = new QTableWidgetItem(QString("未识别"));
        }else
            itemjudge = new QTableWidgetItem(QString("正确识别"));
        QTableWidgetItem *itemTime = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
//        QTableWidgetItem *itemopre = new QTableWidgetItem();
        QPushButton *btn_edit = new QPushButton("结算");
        connect(btn_edit,&QPushButton::clicked,this,&RecognitionCar::Close_On_Account);

        ui->tab->setItem(count, 0, itemDeviceID);
        ui->tab->setItem(count, 1, itemplate);
        ui->tab->setItem(count, 2, itemjudge);
        ui->tab->setItem(count, 3, itemTime);
        ui->tab->setCellWidget(count,4,btn_edit);

        ui->tab->item(count,0)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(count,1)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(count,2)->setTextAlignment(Qt::AlignCenter);
        ui->tab->item(count,3)->setTextAlignment(Qt::AlignCenter);

}

void RecognitionCar::selectdata()
{
    QList<QTableWidgetItem *> items=ui->tab->selectedItems();
    int count=items.count();
    for(int i=0;i<count;++i)
    {
        //int row=ui->tab->row(items.at(i));
        QTableWidgetItem *it=items.at(i);
        QString text=it->text();
        qDebug()<<text<<endl;
    }
}

void RecognitionCar::initshadow()
{

    QGraphicsDropShadowEffect  *widget_shadow=new QGraphicsDropShadowEffect(this);
    widget_shadow->setOffset(0,0);

    widget_shadow->setColor(QColor("#080808"));

    widget_shadow->setBlurRadius(18);

    ui->widget->setGraphicsEffect(widget_shadow);
}

void RecognitionCar::Close_On_Account()
{
    QString timestr=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QDateTime curtime=QDateTime::fromString(timestr,"yyyy-MM-dd hh:mm:ss");
    QPushButton *obj=qobject_cast<QPushButton*>(this->sender());
    if(nullptr==obj)
    {
        return ;
    }
    int x = obj->frameGeometry().x();
    int y = obj->frameGeometry().y();
    QModelIndex index = ui->tab->indexAt(QPoint(x, y));
    int row = index.row();
    qDebug()<<"按钮所在行为:"<<row<<endl;
    QList<QString> allstr;
    for(int i=0;i<4;++i)
    {
        QTableWidgetItem* item = ui->tab->item(row,i);
        allstr<<item->text();
    }
    QDateTime oldtime=QDateTime::fromString(allstr[3],"yyyy-MM-dd hh:mm:ss");
//    QTime time;
//    time.setHMS(0,0,0,0);
//    QTime chatime= time.addSecs(oldtime.secsTo(curtime));
//    QString time_str=chatime.toString();
//    qint64 time_str=oldtime.secsTo(curtime);
    qint64 intervaltime=curtime.toTime_t()-oldtime.toTime_t();
    QString time_str=tr("%1").arg(intervaltime);
    int money=time_str.toInt()*2;

    QString info="入库车辆信息为: "+allstr[1].append('\n')+
                 +"入库时间为: "+allstr[3].append('\n')+
                  "出库时间为: "+timestr.append('\n')+
                  "您总共停留: "+time_str+QString("秒").append('\n')+
                  QString("根据本场地的收费标准: 2元/s(秒)").append('\n')+
                  "您一共需要支付: "+ QString("%1").arg(money)+"元";

    connect(this,&RecognitionCar::carinfo,_cardata,&DataThread::getcardata);

    QMessageBox msgBox (QMessageBox::NoIcon, "结算信息",info, QMessageBox::Yes | QMessageBox::No, NULL);
    msgBox.button(QMessageBox::Yes)->setText("结算");
    msgBox.button(QMessageBox::No)->setText("返回");
    if(msgBox.exec()==QMessageBox::Yes)
    {
        emit carinfo(allstr[1],allstr[3],timestr,money);
        qDebug()<<"点击yes"<<endl;
        mysqltime->start();

    }

}


RecognitionCar::~RecognitionCar()
{
    delete ui;
}


void RecognitionCar::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QPoint off_temp;
        off_temp=event->globalPos()-offest;
        move(off_temp);
    }
    QWidget::mouseMoveEvent(event);

}

void RecognitionCar::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        offest=event->globalPos()-pos();
    }
    QWidget::mousePressEvent(event);



}

void RecognitionCar::mouseReleaseEvent(QMouseEvent *event)
{
   QWidget::mouseReleaseEvent(event);
}

void RecognitionCar::showEvent(QShowEvent *event)
{

    QWidget::showEvent(event);
}

