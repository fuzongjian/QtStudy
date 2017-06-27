#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimerEvent>
#include "mylabel.h"
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
private:
    Ui::MyWidget *ui;
    int timerID_1;
    int timerID_2;
};

#endif // MYWIDGET_H
