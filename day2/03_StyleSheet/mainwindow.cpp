#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:red;"
                             "background-image:url();"
                             "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
