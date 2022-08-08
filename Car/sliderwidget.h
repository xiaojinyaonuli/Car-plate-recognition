#ifndef SLIDERWIDGET_H
#define SLIDERWIDGET_H

#include <QWidget>

namespace Ui {
class SliderWidget;
}

class SliderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SliderWidget(QWidget *parent = nullptr);
    ~SliderWidget();

private:
    Ui::SliderWidget *ui;
};

#endif // SLIDERWIDGET_H
