#include "mainwindow.h"

#include <QApplication>
//#include "easypr.h"
//#include "easypr/util/switch.hpp"
//#include"test/plate.hpp"
#include"mainobject.h"
#include "recognitioncar.h"
#include<QDebug>
#include<QMessageBox>
#include"customerclass.h"
#include"registerpage.h"
#include<QVBoxLayout>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlError>

//using namespace easypr;
//using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    CPlateRecognize pr;
//    pr.setDetectType(PR_DETECT_CMSER|PR_DETECT_COLOR);
//    vector<CPlate> plateVec;
//    Mat src=imread("D://EasyPR-master//EasyPR-master//resources//image//plate_detect.jpg");
//    pr.setResultShow(false);
//    int result=pr.plateRecognize(src,plateVec);
//    qDebug()<<result;
//    pr.getDetectShow();
//    CPlate plate=plateVec.at(0);
//    string license=plate.getPlateStr();
//    QString lince1=QString::fromLocal8Bit(license.c_str());
//    qDebug()<<"识别出的车牌为:"<<lince1;
//    //demo::test_plate_detect();

//    MainWindow w;
//    w.show();

//       ActivityWidget *p=new ActivityWidget(true,true);
//       QVBoxLayout *Filevlayout=new QVBoxLayout(p);
//       p->setLayout(Filevlayout);

//       p->setNormallColor("#F0FFFF");
//       InputText *s=new InputText("adasd","aasdasd",true,p);
//       Filevlayout->addWidget(s);

//       s->setMinimumSize(200,50);
//       p->show();
//    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("118.195.179.135");
//    db.setPort(3306);
//    db.setDatabaseName("yourdb");
//    db.setUserName("root");
//    db.setPassword("1314jinshen");

//    if (!db.open())
//            qDebug() << "Failed to connect to root mysql admin"<<db.lastError().text();
//        else qDebug() << "open";
      RegisterPage *s=new RegisterPage();
      s->show();
//        RecognitionCar *s=new RecognitionCar(nullptr);
//        s->show();

//    box.setText(lince1);
//    MainObject ob;
//    ob.setInit();
    return a.exec();
}
