#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QHostAddress>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    void dealMsg();//槽函数，处理对方发过来的数据
private slots:


    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::ClientWidget *ui;
    QUdpSocket *clientSocket;
};

#endif // CLIENTWIDGET_H
