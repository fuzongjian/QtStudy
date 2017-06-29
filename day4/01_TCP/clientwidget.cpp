#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    tcpSocket = NULL;
    tcpSocket = new QTcpSocket(this);


    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
    {
        ui->textEditRead->setText("成功和服务器建立连接");
    }
            );

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        QByteArray array = tcpSocket->readAll();
        ui->textEditRead->append(array);
    }
            );


}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButtoncConnect_clicked()
{
    QString IP = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    // 主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(IP),port);
}

void ClientWidget::on_pushButtonSend_clicked()
{
    // 获取编辑框内容
    QString str = ui->textEditWrite->toPlainText();
    // 发送数据
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->setText("");
}

void ClientWidget::on_pushButtonClose_clicked()
{
    //自己和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
