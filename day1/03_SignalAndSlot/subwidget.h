#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);
    void sendSlot();
private:
    QPushButton b;
signals:
    /* 信号必须有signals关键字来申明
     * 信号没有返回值，但可以有参数
     * 信号就是函数的申明，只需申明，无需定义
     * 信号可以重载
     */
    void mySignal();
    void mySignal(int,QString);
public slots:
};

#endif // SUBWIDGET_H
