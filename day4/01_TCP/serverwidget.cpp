#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);


    tcpSocket = NULL;
    tcpServer = NULL;

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    setWindowTitle("服务器：8888");
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        // 取出建立好的连接套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方的IP和端口
        QString IP = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:客户端成功连接").arg(IP).arg(port);
        ui->textEditRead->setText(temp);



        // tcpSocket取出之后才能用
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=]()
        {
            //从通信套接字中取出内容
           QByteArray array = tcpSocket->readAll();
           ui->textEditRead->append(array);
        }
                );


    }
            );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(tcpSocket == NULL)return;
    QString str = ui->textEditWrite->toPlainText();
    // 给对方发送数据，使用套接字是tcpsocket
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->setText("");
}

void ServerWidget::on_buttonClose_clicked()
{
    if(tcpSocket == NULL)return;
    // 主动和客户端端口断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
