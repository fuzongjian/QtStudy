#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeout(){
    while (isStop == false) {
        QThread::sleep(1);
        emit mySignal();
        qDebug()<<"子主线程好："<<QThread::currentThread();

        if(isStop == true){
            break;
        }
    }
}
void MyThread::setFlag(bool flag){
    isStop = flag;
}
