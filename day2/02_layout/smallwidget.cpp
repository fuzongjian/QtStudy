#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox * spin = new QSpinBox(this);
    QSlider * slider = new QSlider(Qt::Horizontal,this);

    QHBoxLayout * layout = new QHBoxLayout;//如果没有指定父对象，需要setLayout设置
    layout->addWidget(spin);
    layout->addWidget(slider);
    setLayout(layout);


    // 强制类型转换
    connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,&QSlider::setValue);

    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}

