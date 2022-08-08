/*****************************************
 * 作者:
 * 日期: 2022.5.12
 * 功能：初始化闪屏界面并加载主界面
 * ***************************************/
#include "mainobject.h"
#include "mainwindow.h"
#include"customerclass.h"
MainObject::MainObject(QObject *parent) :
    QObject(parent)
{
}

MainObject::~MainObject()
{
    delete m_mainWindow;
}

void MainObject::setInit()
{
    SplashScreen::getInstance()->setStagePercent(0,tr("初始化应用程序 ..."));
    m_mainWindow = new MainWindow(nullptr);
    m_mainWindow->setWindowTitle(tr("JS车牌识别系统"));
    m_mainWindow->setWindowIcon(QIcon(":/image/icon.png"));
    SplashScreen::getInstance()->setStart(m_mainWindow, tr("JS车牌识别系统"), QString(":/image/icon.png"));
    SplashScreen::getInstance()->setStagePercent(10, tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(40, tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(80, tr("加载界面 ..."));
    SplashScreen::getInstance()->setStagePercent(100, tr("加载完毕！"));
    SplashScreen::getInstance()->setFinish();
    qDebug()<<"显示"<<endl;
    m_mainWindow->showNormal();


}
