#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    // 很复杂的数据处理，耗时5s
    sleep(5);
    // 处理完之后，发出信号
    emit isDone();
}
