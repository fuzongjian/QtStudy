#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QThread>

#include "mythread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealTimeout();// 定时器槽函数
    void dealDone();// 线程结束函数
    void stopThread();//关闭线程
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer * myTimer;
    MyThread * thread;// 线程对象

};

#endif // WIDGET_H
