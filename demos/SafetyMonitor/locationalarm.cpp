#include "locationalarm.h"
#include "ui_locationalarm.h"

LocationAlarm::LocationAlarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocationAlarm)
{
    ui->setupUi(this);
}

LocationAlarm::~LocationAlarm()
{
    delete ui;
}
