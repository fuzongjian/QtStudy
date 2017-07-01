#include "titlewidget.h"
#include "ui_titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);
}

void TitleWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/images/skin"));
}


TitleWidget::~TitleWidget()
{
    delete ui;
}
