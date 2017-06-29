#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 分配空间，指定父对象，主要涉及到内存的释放
    udpSocket = new QUdpSocket(this);
    // 绑定
    udpSocket->bind(8888);
    setWindowTitle("服务器端口为：8888");
    // 当对方成功发送数据过来
    // 自动触发readyRead
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);


}
void Widget::dealMsg(){
    // 读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;
    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0){
        //格式化
        QString str = QString("[%1:%2] %3").arg(cliAddr.toString()).arg(port).arg(buf);
        //给编辑去设置内容
        ui->textEdit->setText(str);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    // 先获取对方的IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    // 获取编辑去内容
    QString str = ui->textEdit->toPlainText();
    // 给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}

void Widget::on_buttonClose_clicked()
{

}
