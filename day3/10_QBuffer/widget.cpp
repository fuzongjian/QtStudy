#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>

#include <QDataStream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;

    QBuffer memFile(&array);//创建内存文件
    memFile.open(QIODevice::WriteOnly);
    memFile.write("1111111111111");
    memFile.write("2222222222");
    memFile.close();


    qDebug()<<memFile.buffer();
    qDebug()<<"array == "<<array;

    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream << QString("测试") << 250;
    memFile1.close();
    qDebug()<<memFile1.buffer();


    memFile1.open(QIODevice::ReadOnly);
    QDataStream out;
    out.setDevice(&memFile1);
    QString str;
    int a;
    out >> str >> a;
    memFile1.close();
    qDebug()<< str.toUtf8().data()<<a;
}

Widget::~Widget()
{
    delete ui;
}
