#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap绘图

    // 绘图设置  400*300
    QPixmap pixmap(400,300);

    QPainter p(&pixmap);
    // 填充颜色
//    p.fillRect(0,0,400,300,QBrush(Qt::white));
    pixmap.fill(Qt::white);

    p.drawPixmap(0,0,80,80,QPixmap("../image/timg.jpg"));
    //保存图片
    pixmap.save("../pixmap.png");


//   Qpicture



}
// QPixmap:针对屏幕进行优化，和平台相关，不能对图片进行修改
// QImage：和平台无关，可以对图片进行修改，在线程中绘图
// QPicture:保存图片的状态（二进制文件）
Widget::~Widget()
{
    delete ui;
}
