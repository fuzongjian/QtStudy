#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    tcpSocket = new QTcpSocket(this);
    isStart = true;
    ui->progressBar->setValue(0);
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        // 取出接收的内容
        QByteArray buf = tcpSocket->readAll();
        if(isStart == true){// 接收头
            isStart = false;
            // 解析头部信息
            fileName = QString(buf).section("##",0,0);
            fileSize = QString(buf).section("##",1,1).toInt();
            ui->progressBar->setMaximum(fileSize);
            recvSize = 0;
            // 初始化
            // 打开文件
            file.setFileName(fileName);
            bool isOk = file.open(QIODevice::WriteOnly);
            if(isOk == false){
                qDebug()<<"打开出错";
                isStart = true;
            }
        }else{
            qint64 len = file.write(buf);
            recvSize += len;
            ui->progressBar->setValue(recvSize);
            if(recvSize == fileSize){
                // 关闭文件
                file.close();
                QMessageBox::information(this,"完成","文件接收完成");
                tcpSocket->disconnectFromHost();
                tcpSocket->close();
                isStart = true;
            }
        }
    }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    // 获取服务器IP与端口
    QString IP = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(IP),port);

}
