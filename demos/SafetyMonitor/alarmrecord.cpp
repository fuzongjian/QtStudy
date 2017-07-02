#include "alarmrecord.h"
#include "ui_alarmrecord.h"

AlarmRecord::AlarmRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmRecord)
{
    ui->setupUi(this);
}

AlarmRecord::~AlarmRecord()
{
    delete ui;
}
