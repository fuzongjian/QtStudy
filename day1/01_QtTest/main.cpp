#include "mywidget.h"
// QApplication 应用程序类
// 头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    // 有且只有一个应用程序类的对象
    QApplication a(argc, argv);
    // MyWidget继承于QWidget，QWidget是一个窗口基类
    // MyWidget也是窗口类、
    // w也是一个窗口

    MyWidget w;
    w.show();

    return a.exec();
}
