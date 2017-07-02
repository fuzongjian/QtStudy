#include "titlewidget.h"
#include "ui_titlewidget.h"
#include <QDebug>
#include <QtGui>
TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);
    ui->buttonClose->loadPixmap(":/images/close_button");
    ui->buttonClose->setToolTip("关闭程序");
    connect(ui->buttonClose,SIGNAL(clicked()),this,SIGNAL(closeWindow()));
    ui->buttonMin->loadPixmap(":/images/min_button");
    ui->buttonMin->setToolTip("最小化");
    connect(ui->buttonMin,SIGNAL(clicked(bool)),this,SIGNAL(showMin()));


    button_list.append(ui->buttonMonitor);
    ui->buttonMonitor->setText("监控管理");
    button_list.append(ui->buttonLocation);
    ui->buttonLocation->setText("位置报警");
    button_list.append(ui->buttonAlarm);
    ui->buttonAlarm->setText("报警记录");
    button_list.append(ui->buttonHandle);
    ui->buttonHandle->setText("操作日志");
    button_list.append(ui->buttonSystem);
    ui->buttonSystem->setText("系统设置");

    QStringList string_list;
    string_list<<":/images/6"<<":/images/7"<<":/images/8"<<":/images/9"
        <<":/images/10";
    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i = 0; i < button_list.size(); i ++){
        ToolButton *tool_button = button_list.at(i);
        tool_button->setBgImage(string_list.at(i));
        connect(tool_button,SIGNAL(clicked()),signal_mapper,SLOT(map()));
        signal_mapper->setMapping(tool_button,QString::number(i));
        if(i == 0){
            tool_button->setMousePress(true);
        }
    }
    connect(signal_mapper,SIGNAL(mapped(QString)),this,SLOT(turnPage(QString)));
}

void TitleWidget::turnPage(QString current_page){
    bool ok;
    int current_index = current_page.toInt(&ok, 10);

    for(int i=0; i<button_list.count(); i++)
    {
        ToolButton *tool_button = button_list.at(i);
        if(current_index == i)
        {
            tool_button->setMousePress(true);
        }
        else
        {
            tool_button->setMousePress(false);
        }
    }
}

void TitleWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/images/skin"));
}

void TitleWidget::mousePressEvent(QMouseEvent *e)
{
    press_point = e->pos();
    is_move = true;
}

void TitleWidget::mouseMoveEvent(QMouseEvent *e)
{
//    QMainWindow* mainwindow = qobject_cast< MainWindow *>( swf-> parent());
    if((e->buttons() == Qt::LeftButton) && is_move)
    {

        static QMainWindow * mainWindow = qobject_cast< QMainWindow *>(this->parent()->parent());
        QPoint parent_point = mainWindow->pos();
        parent_point.setX(parent_point.x() + e->x() - press_point.x());
        parent_point.setY(parent_point.y() + e->y() - press_point.y());
        mainWindow->move(parent_point);
    }
}

void TitleWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(is_move)
    {
        is_move = false;
    }
}
TitleWidget::~TitleWidget()
{
    delete ui;
}
