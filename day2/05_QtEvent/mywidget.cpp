#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QMessageBox>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 定时器启动
    timerID_1 = this->startTimer(1000);
    this->timerID_2 = this->startTimer(500);


    connect(ui->pushButton,&MyButton::clicked,
            [=]()
    {
        qDebug()<<"click";
    }
            );



    // 安装过滤器
    ui->eventfilter->installEventFilter(this);
    ui->eventfilter->setMouseTracking(true);
}
void MyWidget::keyPressEvent(QKeyEvent *event){
     qDebug()<<event->key();
     if(event->key() == Qt::Key_A){
        qDebug()<<"Qt::Key_A";
     }
}
void MyWidget::timerEvent(QTimerEvent *event){
    if(event->timerId() == timerID_1){
        static int sec = 0;
        sec++;
        QString text = QString("timerCount %1").arg(sec);
        ui->label->setText(text);

        if(sec == 5){
            this->killTimer(this->timerID_1);
        }
        qDebug()<<"timerID_1"<<timerID_1;
    }else if(event->timerId() == timerID_2){
        qDebug()<<"timerID_2"<<timerID_2;
    }

}
void MyWidget::mousePressEvent(QMouseEvent *e){
    qDebug()<<"------------------";
}


void MyWidget::closeEvent(QCloseEvent *e){
    int ret = QMessageBox::question(this,"question","是否需要关闭窗口");
    if(ret == QMessageBox::Yes){
        // 关闭窗口
        // 处理关闭窗口事件，接收事件，事件就不会往下面传递
        e->accept();
    }else{
        // 不关闭窗口
        // 忽略事件，事件继续给父组件传递
        e->ignore();
    }
}





bool MyWidget::event(QEvent *e){
    // 事件分发
//    switch (e->type()) {
//    case QEvent::Close:
//        closeEvent(e);
//        break;
//    case QEvent::MouseMove:
//        mouseMoveEvent(e);
//        break;
//    default:
//        break;
//    }


    if(e->type() == QEvent::Timer){
        // 干掉定时器
        // 如果返回true，事件停止传播
        // 类型转换
        QTimerEvent *event =  static_cast<QTimerEvent *>(e);
        timerEvent(event);
        return true;
    }else if(e->type() == QEvent::KeyPress){

    }else{
        return QWidget::event(e);
    }

}
bool MyWidget::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->eventfilter){
        // 判断事件
        QMouseEvent *env = static_cast<QMouseEvent *>(e);
        if(e->type() == QEvent::MouseMove){
            ui->eventfilter->setText("mouse_move");
            return true;
        }else{
            return QWidget::eventFilter(obj,e);
        }
    }else{
        return QWidget::eventFilter(obj,e);
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}
