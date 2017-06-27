#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置跟踪鼠标
//    this->setMouseTracking(true);
}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("Mouse Move:(%1,%2)").arg(ev->x()).arg(ev->y());
    this->setText(text);
}
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        qDebug()<<"left";
    }else if(ev->button() == Qt::RightButton){
        qDebug()<<"right";
    }else if(ev->button() == Qt::MidButton){
        qDebug()<<"middle";
    }
    int x = ev->x();
    int y = ev->y();
    // sprinf
    /*
     *  QString str = QString("abc" %1
     */
    QString text = QString("Mouse Press:(%1,%2)").arg(x).arg(y);
    this->setText(text);

}
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("Mouse Release:(%1,%2)").arg(ev->x()).arg(ev->y());
    this->setText(text);
}
void MyLabel::enterEvent(QEvent *event){
    this->setText("进来");
}
void MyLabel::leaveEvent(QEvent *event){
     this->setText("出去");
}
