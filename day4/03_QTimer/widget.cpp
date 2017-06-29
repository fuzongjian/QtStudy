#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    connect(myTimer,&QTimer::timeout,
            [=]()
    {
        static int i = 0;
        i ++;
        ui->lcdNumber->display(i);
    }
            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStart_clicked()
{
    // 启动定时器
    // 时间间隔 100ms
    // 每隔100ms，定时器myTimer自动触发timeout()
    if(myTimer->isActive() == false){
        myTimer->start(100);
    }
}

void Widget::on_buttonStop_clicked()
{
    if(myTimer->isActive() ==true){
        myTimer->stop();
    }
}
