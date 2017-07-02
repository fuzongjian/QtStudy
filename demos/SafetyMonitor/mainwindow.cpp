#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->titleWidget,SIGNAL(showMin()),this,SLOT(showMinimized()));//最小化程序
    connect(ui->titleWidget,SIGNAL(closeWindow()),qApp,SLOT(quit()));// 关闭程序


    connect(ui->titleWidget->button_list.at(0),SIGNAL(clicked(bool)),this,SLOT(changeView_one()));
    connect(ui->titleWidget->button_list.at(1),SIGNAL(clicked(bool)),this,SLOT(changeView_two()));
    connect(ui->titleWidget->button_list.at(2),SIGNAL(clicked(bool)),this,SLOT(changeView_three()));
    connect(ui->titleWidget->button_list.at(3),SIGNAL(clicked(bool)),this,SLOT(changeView_four()));
    connect(ui->titleWidget->button_list.at(4),SIGNAL(clicked(bool)),this,SLOT(changeView_five()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeView_one(){
    qDebug()<<"1";
    ui->mainStack->setCurrentIndex(0);
}
void MainWindow::changeView_two(){
    ui->mainStack->setCurrentIndex(1);
}
void MainWindow::changeView_three(){
    ui->mainStack->setCurrentIndex(2);
}
void MainWindow::changeView_four(){
    ui->mainStack->setCurrentIndex(3);
}
void MainWindow::changeView_five(){
    ui->mainStack->setCurrentIndex(4);
}
