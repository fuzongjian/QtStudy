#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->setStyleSheet("background-color:red;");
}
void Widget::paintEvent(QPaintEvent *){
//    QPainter p(this,)
    QPainter p;// 创建画笔
    p.begin(this);// 指定当前窗口为绘画设备
    p.drawPixmap(0,0,width(),height(),QPixmap("://image/timg.jpg"));
    p.end();
}

Widget::~Widget()
{
    delete ui;
}
