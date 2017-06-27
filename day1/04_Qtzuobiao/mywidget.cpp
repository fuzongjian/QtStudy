#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*v  对于父窗口（主窗口），坐标系统相对于屏幕
     *   原点： 相对于屏幕左上角
     *     X： 往右递增
     *     Y： 往下递增
     *
    */
//    move(100,100);
    QPushButton *b = new QPushButton(this);
    b->move(100,100);
    b->setText("天下第一");
    b->resize(200,200);
    resize(1000,1000);

    QPushButton * b2 = new QPushButton(b);
    b2->setText("天下第二");
    b2->move(10,10);



    MyButton * b3 = new MyButton(this);
    b3->setText("button3");
    // 1、指定父对象后   2、直接或间接继承QObject
    // 子对象如果是动态分配空间的new，不要要手动释放delete
    // 系统自动释放
}

MyWidget::~MyWidget()
{

}
