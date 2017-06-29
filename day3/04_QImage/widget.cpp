#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //   QImage
    QImage image(400,300,QImage::Format_ARGB32);
    QPainter p2;
    p2.begin(&image);
    p2.drawImage(rect(),QImage("../image/timg.jpg"));
    // 对绘图设备前五十个像素进行操作
    for(int i = 0; i < 50; i ++){
        for(int j = 0; j < 50; j++){
            image.setPixel(QPoint(i,j),qRgb(0,255,255));
//            image.pixel(QPoint(i,j))  获取像素点
        }
    }

    p2.end();
    image.save("../image.png");
}
// QPixmap:针对屏幕进行优化，和平台相关，不能对图片进行修改
// QImage：和平台无关，可以对图片进行修改，在线程中绘图
// QPicture:保存图片的状态（二进制文件）
Widget::~Widget()
{
    delete ui;
}
