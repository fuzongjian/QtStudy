#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    clientSocket = new QUdpSocket(this);
    setWindowTitle("8088");
    clientSocket->bind(8088);
//    // 当对方成功发送数据过来
//    // 自动触发readyRead
    connect(clientSocket,&QUdpSocket::readyRead,this,&ClientWidget::dealMsg);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}
void ClientWidget::dealMsg(){
    // 读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;
    qint64 len = clientSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0){
        //格式化
        QString str = QString("[%1:%2] %3").arg(cliAddr.toString()).arg(port).arg(buf);
        //给编辑去设置内容
        ui->textEdit->setText(str);
    }
}


void ClientWidget::on_buttonSend_clicked()
{
    // 先获取对方的IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    // 获取编辑去内容
    QString str = ui->textEdit->toPlainText();
    // 给指定的IP发送数据
    clientSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}

void ClientWidget::on_buttonClose_clicked()
{

}
