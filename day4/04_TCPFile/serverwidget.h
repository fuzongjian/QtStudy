#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QTimer>
namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();
    void sendData();// 发送文件数据
private slots:
    void on_buttonFile_clicked();

    void on_buttonSend_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpSocket * tcpSocket;
    QTcpServer * tcpServer;
    QFile file;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;// 已经发送文件大小
    QTimer timer;// 定时器
};

#endif // SERVERWIDGET_H
