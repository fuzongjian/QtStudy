#include "mybutton.h"
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
void MyButton::mousePressEvent(QMouseEvent *e){
    if(e->button() ==Qt::LeftButton){// 左键被按下
        qDebug()<<"鼠标左键被按下";
       // e->ignore();// 忽略，是按继续往下传递
                    // 事件传递给了父组件，不是给父类（基类）
    }else{
        // 不做处理，交给父类处理
        QPushButton::mousePressEvent(e);
    }
}
