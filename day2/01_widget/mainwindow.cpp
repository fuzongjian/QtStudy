#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button->setText("hello123");

    QString str = ui->lineEdit->text();
    ui->button->setText(str);



    ui->lineEdit->setTextMargins(10,0,0,0);
//    ui->lineEdit->setEchoMode(QLineEdit::Password);



    // 下拉提示
    QStringList list;
    list<<"hello"<<"how are you"<<"hehe";
    QCompleter * com = new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);




    ui->label_text->setText("付宗建");

    ui->label_image->setPixmap(QPixmap("://image/Tulips.jpg"));
    ui->label_image->setScaledContents(true);

    QMovie * movie = new QMovie("://image/timg.gif");
    ui->label_gif->setMovie(movie);
    ui->label_gif->setScaledContents(true);
    movie->start();



    ui->label_url->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->label_url->setOpenExternalLinks(true);


    ui->lcdNumber->display(123);// 设置内容


    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(20);



    ui->webView->load(QUrl("http://www.baidu.com"));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i%3);
}
