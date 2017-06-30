#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
class MyThread : public QObject
{
    // 有信号与槽必须要有下面的宏
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    // 线程处理函数
    void myTimeout();
    void setFlag(bool flag = true);
signals:
    void mySignal();
public slots:
private:
    bool isStop;
};

#endif // MYTHREAD_H
