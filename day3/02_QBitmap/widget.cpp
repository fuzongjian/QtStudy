#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(10,10,100,100,QPixmap("../image/timg.jpg"));


    // QBitmap  图片背景透明
    p.drawPixmap(120,120,100,100,QBitmap("../image/timg.jpg"));
}

Widget::~Widget()
{
    delete ui;
}
