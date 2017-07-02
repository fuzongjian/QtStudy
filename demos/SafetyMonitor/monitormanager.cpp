#include "monitormanager.h"
#include "ui_monitormanager.h"

MonitorManager::MonitorManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorManager)
{
    ui->setupUi(this);
}

MonitorManager::~MonitorManager()
{
    delete ui;
}
