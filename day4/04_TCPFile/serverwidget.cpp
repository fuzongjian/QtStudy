#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    // 绑定监听
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器端口：8888");
    // 两个按钮都不能按
    ui->buttonFile->setEnabled(false);
    ui->buttonSend->setEnabled(false);
    // 如果客户端成功和客户端成功连接，
    // tcpserver会自动触发 newConnection()
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        //取出建立好的连接套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方的IP和端口
        QString IP = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();
        QString str = QString("[%1:%2] 成功连接").arg(IP).arg(port);
        ui->textEdit->setText(str);


        //成功连接后，才能选择文件
        ui->buttonFile->setEnabled(true);


    }
            );

    connect(&timer,&QTimer::timeout,
            [=]()
    {
        // 关闭定时器
        timer.stop();
        //开始发送文件
        sendData();
    }
            );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty() == false){// 如果选择文件的路径有效
        // 读文件信息 (只读)
        fileName.clear();
        fileSize = 0;
        sendSize = 0;
        QFileInfo info(path);
        fileName = info.fileName();
        fileSize = info.size();
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == false){
            qDebug()<<"只读方式打开文件失败";
        }
        // 提示打开的文件路径
        ui->textEdit->append(path);
        ui->buttonFile->setEnabled(false);
        ui->buttonSend->setEnabled(true);
    }else{
        qDebug()<<"选择文件路径出错";
    }
}
// 发送文件按钮
void ServerWidget::on_buttonSend_clicked()
{
    // 先发送文件头信息
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    //发送头部信息
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len > 0){// 头部信息发送成功
        // 发送真正的文件信息，防止TCP黏包，需要通过定时器延时 20ms
        timer.start(20);
    }else{
        qDebug()<<"头信息发送失败";
        file.close();
        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    }
    // 再来发送文件信息

}
void ServerWidget::sendData(){
    qint64 len = 0;
    do{
        char buf[4*1024] = {0};// 每次发送数据的大小
        len = 0;
        // 往文件中读取数据
        len = file.read(buf,sizeof(buf));
        // 发送数据,读多少发多少
        tcpSocket->write(buf,len);

        // 发送的数据要累加
        sendSize += len;
    }while(len>0);

    // 是否发送文件完毕
    if(sendSize == fileSize){
        ui->textEdit->append("文件发送完毕");
        file.close();
        //断开客户端
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        ui->buttonSend->setEnabled(false);
    }
}
