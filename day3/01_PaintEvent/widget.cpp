#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->setStyleSheet("background-color:red;");


    x = 0;
}
void Widget::paintEvent(QPaintEvent *){
//    QPainter p(this,)
    QPainter p;// 创建画笔
    p.begin(this);// 指定当前窗口为绘画设备

    // 背景图
//    p.drawPixmap(0,0,width(),height(),QPixmap("://image/timg.jpg"));
//    p.drawPixmap(rect(),QPixmap("://image/timg.jpg"));

    // 画笔
    QPen pen;
    pen.setWidth(5);
//    pen.setColor(Qt::red);// 设置颜色
    pen.setColor(QColor(14,9,234));// rgb设置颜色
    pen.setStyle(Qt::DashLine);// 设置风格
    p.setPen(pen);

    //直线
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);


    //  创建画刷对象
    QBrush brush;
    brush.setColor(Qt::red);// 设置颜色
    brush.setStyle(Qt::Dense1Pattern);// 设置样式
    p.setBrush(brush);// 把画刷交给画家

    // 矩形
    p.drawRect(150,150,100,50);

    // 画圆
    p.drawEllipse(QPoint(150,150),50,25);



    p.drawPixmap(x,180,80,80,QPixmap("://image/timg.jpg"));

    p.end();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width()){
        x = 0;
    }
    // 刷新窗口，让窗口重绘
    update();//间接调用paintEvent
}
