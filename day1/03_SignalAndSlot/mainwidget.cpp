#include "mainwidget.h"
#include <QDebug>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{

    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("second");
    /*
     * &b1: 信号发出者，指针类型
     * &QPushButton::pressed 处理的信号，   &发出者的类名::信号名字
     * this : 信号接收者
     * &MainWidget::close  槽函数，信号处理函数，  &接收的类名::槽函数名字
     */
    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);


    /*  自定义槽
     * Qt5：任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数、返回值）
     * 由于信号都是没有返回值，所以，槽函数一定没有返回值
    */
    connect(b2,&QPushButton::released,this,&MainWidget::myslot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    /*      信号：短信
     *      槽函数： 接收短信的手机
     *
     */
    setWindowTitle("老大");
    // 显示子窗口
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);
    connect(&b3,&QPushButton::released,this,&MainWidget::changeWin);

    // 处理子窗口的信号
    // Qt5信号连接
    // 如果有信号重载的话  比较麻烦
//    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
//    connect(&sub,funSignal,this,&MainWidget::dealSub);

//    void (SubWidget::*testSignal)(int,QString) = &SubWidget::mySignal;
//    connect(&sub,testSignal,this,&MainWidget::dealSlot);


    // Qt4信号连接
    // Qt4槽函数必须有slots关键字来修饰
    // SINGNAL SLOT 将函数名 -> 字符串， 不进行错误检查（将mySignal方法名写错，也不会报错）
   // 缺点： 1、需要关键字修饰   2、不进行错误检查
    connect(&sub,SIGNAL(mySignal()),this,SLOT(dealSub()));
    connect(&sub,SIGNAL(mySignal(int,QString)),this,SLOT(dealSlot(int,QString)));


    // Lambda表达式 匿名函数对象
    // C++11 增加的新特性
    // Qt配合信号一起使用，非常方便
    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150,150);
    int a=10,b=5;
    connect(b4,&QPushButton::released,
            // [b4,a,b]  可传参、以数组的形式传递
            // [=]  把外部所有局部变量、类中所有成员以值传递方式（只读）    常用
            // [=]() mutable 即可以变成可读可写
            // this : 类中所有成员以值传递方式
            // & : 把外部所有局部变量、引用符号
            [=]() mutable
    {
        b4->setText("123");
        qDebug()<<"1111"<<"a === "<<a<<"b === "<<++b;
    }
            );


    // 信号传参
    connect(b4,&QPushButton::clicked,
            // [b4,a,b]  可传参、以数组的形式传递
            // [=]  把外部所有局部变量、类中所有成员以值传递方式（只读）    常用
            // [=]() mutable 即可以变成可读可写
            // this : 类中所有成员以值传递方式
            // & : 把外部所有局部变量、引用符号
            [=](bool isCheck)
    {

        qDebug()<<isCheck;
    }
            );


    resize(400,300);

}
void MainWidget::myslot(){
    b2->setText("123");
}
void MainWidget::dealSlot(int a,QString b){
    // b.toUtf8()  ->   字节数组QByteArray
    // ....data()  ->   QByteArray -> char*
    qDebug()<<a<<b.toUtf8().data();
}

void MainWidget::changeWin(){
    //子窗口显示
    // 本窗口隐藏
    sub.show();
    this->hide();
}
void MainWidget::dealSub(){
   sub.hide();
   this->show();
}

MainWidget::~MainWidget()
{

}
