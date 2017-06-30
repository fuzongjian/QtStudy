#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include "mythread.h"
#include <QThread>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void getImage(QImage);// 槽函数
    void stopThread();// 关闭线程
private slots:

private:
    Ui::Widget *ui;
    QImage image;
    MyThread * myT;// 自定义线程对象
    QThread * thread;// 子线程

};

#endif // WIDGET_H
