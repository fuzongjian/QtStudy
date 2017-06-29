#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QImage>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);
    p.drawPixmap(0,0,80,80,QPixmap("../image/timg.jpg"));
    p.drawLine(50,50,150,50);
    p.end();
    picture.save("../picture.jpg");// 保存的是二进制文件
}
void Widget::paintEvent(QPaintEvent *){

#if 0
    QPicture pic;
    pic.load("../picture.jpg");
    QPainter p(this);
    p.drawPicture(0,0,pic);
#endif

    QPainter p(this);
//    QPixmap pixmap;
//    pixmap.load(("../image/timg.jpg"));
//    // QPixmap 转化为  QImage
//    QImage tempImage = pixmap.toImage();
//    p.drawImage(rect(),tempImage);

    QImage image;
    image.load("../image/timg.jpg");
    // QImage 转化为 QPixmap
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(rect(),tempPixmap);


}
// QPixmap:针对屏幕进行优化，和平台相关，不能对图片进行修改
// QImage：和平台无关，可以对图片进行修改，在线程中绘图
// QPicture:保存图片的状态（二进制文件）
Widget::~Widget()
{
    delete ui;
}
