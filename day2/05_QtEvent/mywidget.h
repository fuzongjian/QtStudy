#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QEvent>
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


    // 事件忽略和接收
    void mousePressEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);

    // 事件分发
    bool event(QEvent *);


    // 事件过滤器
    bool eventFilter(QObject *, QEvent *);
private:
    Ui::MyWidget *ui;
    int timerID_1;
    int timerID_2;
};

#endif // MYWIDGET_H
