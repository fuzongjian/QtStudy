#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 自定义类对象，不可以指定父对象
    myT = new MyThread();
    // 创建子线程
    thread = new QThread(this);
    // 把自定义模块添加到子线程
    myT->moveToThread(thread);
    //启动子线程，但是并没有启动线程处理函数
    thread->start();
    // 线程处理函数，必须通过signal - slot
    connect(ui->pushButton,&QPushButton::pressed,myT,&MyThread::drawImage);
    connect(myT,&MyThread::updateImage,this,&Widget::getImage);
    connect(this,&Widget::destroyed,this,&Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e){
    // 创建画家，指定绘图设备为窗口
    QPainter p(this);
    p.drawImage(50,50,image);
}
void Widget::getImage(QImage temp){
    image = temp;
    update();//更新窗口，间接调用paintEvent（）
}
void Widget::stopThread(){
    thread->quit();
    thread->wait();
    delete myT;
}
