#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar * mBar = menuBar();
    setMenuBar(mBar);
    QMenu * menu = mBar->addMenu("对话框");
    QAction * p1 = menu->addAction("模态对话框");

    connect(p1,&QAction::triggered,
            []()
    {
        QDialog dlg;
        dlg.exec();
        qDebug()<<"模态对话框";
    }
            );


    QAction * p2 = menu->addAction("非模态对话框");

    connect(p2,&QAction::triggered,
            [=]()
    {
        // 不会造成内存泄漏
//        dlg.show();
//        qDebug()<<"非模态对话框";


        //这样的话，内存得不到释放，内存泄漏
//        QDialog * dialog = new QDialog(this);
//        dialog->show();
//        qDebug()<<"非模态对话框";

        // 关闭的时候让其释放（不指定父对象）
          QDialog * dialog = new QDialog;
          dialog->setAttribute(Qt::WA_DeleteOnClose);// 关键点
          dialog->show();
          qDebug()<<"非模态对话框";
    }
            );



    QAction *p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=]()
    {
        QMessageBox::about(this,"about","关于Qt");
    }
            );

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,
            [=]()
    {
        int ret = QMessageBox::question(this,"question","are you ok?");
        switch (ret) {
        case QMessageBox::Yes:
            qDebug()<<"i am ok";
            break;
        case QMessageBox::No:
            qDebug()<<"i am no";
            break;
        default:
            break;
        }
    }
            );


    QAction *p5 = menu->addAction("文件对话框");
    connect(p5,&QAction::triggered,
            [=]()
    {
       QString path = QFileDialog::getOpenFileName(
                    this,
                    "open",
                    "../",
                   "source(*.cpp *.h);;Text(*.txt);;all(*.*)"
                    );
       qDebug()<<"path == "<<path;
    }
            );



}

MainWindow::~MainWindow()
{

}
