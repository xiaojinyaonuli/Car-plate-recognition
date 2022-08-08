#include "sliderwidget.h"
#include "ui_sliderwidget.h"

SliderWidget::SliderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SliderWidget)
{
    ui->setupUi(this);
}

SliderWidget::~SliderWidget()
{
    delete ui;
}
