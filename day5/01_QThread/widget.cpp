#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    // 只要启动，自动触发timeout（）
    connect(myTimer,&QTimer::timeout,this,&Widget::dealTimeout);


    thread = new MyThread(this);
    connect(thread,&MyThread::isDone,this,&Widget::dealDone);
    // 当按窗口右上角X时，窗口触发destroyed
    connect(this,&Widget::destroyed,this,&Widget::stopThread);
}
void Widget::dealTimeout(){
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}
void Widget::dealDone(){
    qDebug()<<"it is over";
    myTimer->stop();
}
void Widget::stopThread(){
    // 停止线程
    thread->quit();
    //等待线程处理完手头工作，
    thread->wait()
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(myTimer->isActive() == false){
        myTimer->start(100);
    }

    // 启动线程，处理数据
    thread->start();
}
