#include <QApplication>
#include <QWidget>// 窗口控件基类
#include <QPushButton>
int main(int argc,char **argv){
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("HelloQt");// 设置标题


    // 创建按钮
    QPushButton button;
    button.setText("按钮");
    //    button.show();  设置了父对象就可以不用调用此函数
    /*
     *  如果不指定父对象，对象和对象（窗口和窗口）没有关系，独立
     *  a指定b为它的父对象，a放在b的上面
     * 1） setParent
     * 2)  通过构造函数进行传参
     * 指定父对象，只需要父对象显示，上面的子对象就自动显示
    */
    button.move(100,100);// 移动坐标
    button.setParent(&w);// 指定父对象

    //通过构造函数传参
    QPushButton button2(&w);
    button2.setText("second");

    w.show();
    app.exec();
    return 0;
}
