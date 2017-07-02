#include "handlelog.h"
#include "ui_handlelog.h"

HandleLog::HandleLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandleLog)
{
    ui->setupUi(this);
}

HandleLog::~HandleLog()
{
    delete ui;
}
