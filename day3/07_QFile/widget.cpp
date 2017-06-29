#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <qdebug.h>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty() ==false){
        //文件对象
        QFile file(path);
        // 打开文件，只读模式
        bool status = file.open(QIODevice::ReadOnly);
        if(status == true){
#if 0
            // 读文件，默认只是别utf8编码
            // 一次性读完
            QByteArray array = file.readAll();
            ui->textEdit->setText(array);
#endif
            QByteArray array;
            while (file.atEnd() == false) {
               // 度一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);

        }
        // 关闭文件
        file.close();



        // 获取文件信息
        QFileInfo info(path);
        qDebug()<<"文件名"<<info.fileName();
        qDebug()<<"文件后缀"<<info.suffix();
        qDebug()<<"文件大小"<<info.size();
        qDebug()<<"文件创建时间"<<info.created().toString("yyyy-MM-dd hh:mm:ss");
    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(path.isEmpty() == false){
        QFile file ;// 创建文件对象
        // 关联文件名字
        file.setFileName(path);
        //打开文件，只写模式
        bool isok = file.open(QIODevice::WriteOnly);
        if(isok == true){
            // 获取编辑去内容
            QString str = ui->textEdit->toPlainText();
            // 写文件

            // QString -> QByteArray
//            file.write(str.toUtf8());

            // QString -> C++ string  ->  char*
//            file.write(str.toStdString().data());

            file.write(str.toLocal8Bit());

            // QString -> QByteArray
            QString buf = "123";
            QByteArray a = buf.toUtf8();// 中文
            a = buf.toLocal8Bit();// 本地编码

            // QByteArray -> char *
            char *b = a.data();

            // char* -> QString
            char *p = "abc";
            QString c = QString(p);

        }
        file.close();
    }
}
