#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#define cout qDebug() <<"["<<__FILE__<<":"<<__LINE__<<"]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

   writeData();
   readData();
}
void Widget::writeData(){
    // 创建文件路径
    QFile file("../test.txt");
    // 打开文件 只写方式
   bool isopen = file.open(QIODevice::WriteOnly);
   if(isopen == true){

       // 创建数据流，和file文件关联
       // 往数据流中写数据，相当于往文件里写数据
       QDataStream stream(&file);
       stream <<QString("主要看气质")<<250;
       file.close();
   }
}
void Widget::readData(){
    // 创建文件路径
    QFile file("../test.txt");
    // 打开文件 只写方式
   bool isopen = file.open(QIODevice::ReadOnly);
   if(isopen == true){

       // 创建数据流，和file文件关联
       // 往数据流中读数据，相当于往文件里读数据
       QDataStream stream(&file);
       // 读的时候，按写的顺序读取数据
       QString str;
       int a;
       stream >> str >> a;
       file.close();
       cout<<"str == "<<str.toUtf8().data()<<" a == "<<a;
   }
}

Widget::~Widget()
{
    delete ui;
}
