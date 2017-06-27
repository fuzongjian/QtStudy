#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 定时器启动
    timerID_1 = this->startTimer(1000);
    this->timerID_2 = this->startTimer(500);
}
void MyWidget::keyPressEvent(QKeyEvent *event){
     qDebug()<<event->key();
     if(event->key() == Qt::Key_A){
        qDebug()<<"Qt::Key_A";
     }
}
void MyWidget::timerEvent(QTimerEvent *event){
    if(event->timerId() == timerID_1){
        static int sec = 0;
        sec++;
        QString text = QString("timerCount %1").arg(sec);
        ui->label->setText(text);

        if(sec == 5){
            this->killTimer(this->timerID_1);
        }
        qDebug()<<"timerID_1"<<timerID_1;
    }else if(event->timerId() == timerID_2){
        qDebug()<<"timerID_2"<<timerID_2;
    }

}

MyWidget::~MyWidget()
{
    delete ui;
}
