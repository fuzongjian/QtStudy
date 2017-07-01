#include "titlewidget.h"
#include "ui_titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);
}

TitleWidget::~TitleWidget()
{
    delete ui;
}
