#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <QFileDialog>
#define cout qDebug() <<"["<<__FILE__<<":"<<__LINE__<<"]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::writeData(){
    QFile file;
    file.setFileName("../demo.txt");
    bool isopen = file.open(QIODevice::WriteOnly);
    if(isopen == true){
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");
        stream << QString("主要看气质") <<250;
    }
    file.close();
}
void Widget::readData(){
    QFile file;
    file.setFileName("../demo.txt");
    bool isopen = file.open(QIODevice::ReadOnly);
    if(isopen == true){
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");
        QString str;
        int a;
        stream >> str >> a;
        cout<<"str == "<<str.toUtf8().data()<<" a == "<<a;
    }
    file.close();
}

void Widget::on_pushButton_clicked()
{

    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty() == false){
        QFile file;
        file.setFileName(path);
        bool isopen = file.open(QIODevice::ReadOnly);
        if(isopen == true){
            QTextStream stream(&file);
            //指定编码
            stream.setCodec("UTF-8");

            QString content = stream.readAll();
            ui->textEdit->setText(content);
            QString str;
            int a;
            stream >> str >> a;
            cout<<"str == "<<str.toUtf8().data()<<" a == "<<a;
        }
        file.close();
    }


}
