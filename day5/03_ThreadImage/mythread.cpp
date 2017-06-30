#include "mythread.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}
void MyThread::drawImage(){
    // 定义一个绘图设备
    QImage image(500,500,QImage::Format_ARGB32);
    // 定义画家，指定绘图设备
    QPainter p(&image);
    // 定义画笔对象
    QPen pen;
    pen.setWidth(5);
    // 把画笔交个画家
    p.setPen(pen);
    //定义画刷
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    // 把画刷交个画家
    p.setBrush(brush);
    // 定义5个点
    QPoint a[] =
    {
      QPoint(qrand()%500,qrand()%500),
      QPoint(qrand()%500,qrand()%500),
      QPoint(qrand()%500,qrand()%500),
      QPoint(qrand()%500,qrand()%500),
      QPoint(qrand()%500,qrand()%500)
    };
    p.drawPolygon(a,5);

    // 通过信号 发送图片
    emit updateImage(image);
}

