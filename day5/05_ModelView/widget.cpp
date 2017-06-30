#include "widget.h"
#include "ui_widget.h"
#include <QSqlRecord>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("qt");
    if(db.open() == false){
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    // 设置模型
    model = new QSqlTableModel(this);
    // 指定使用那个表
    model->setTable("student");
    //把model放到view里面，
    ui->tableView->setModel(model);
    // 显示model里面的数据
    model->select();

    model->setHeaderData(0,Qt::Horizontal,"序号");
    // 设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置view中的数据库不允许修改
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonAdd_clicked()
{
    // 添加一个空记录
    QSqlRecord record = model->record();// 获取空记录
    // 获取行号
    int row = model->rowCount();
    model->insertRecord(row,record);
}

void Widget::on_buttonSure_clicked()
{
    model->submitAll();// 提交动作
}

void Widget::on_buttonCancle_clicked()
{
    model->revertAll();// 取消所有动作
    model->submitAll();// 提交动作
}

void Widget::on_buttonDel_clicked()
{
    // 获取选中的模型
   QItemSelectionModel * selectModels = ui->tableView->selectionModel();
   // 取出模型里面的索引
   QModelIndexList list = selectModels->selectedRows();
   // 删除所有行
   for(int i = 0; i < list.size(); i ++){
       model->removeRow(list.at(i).row());
   }

}

void Widget::on_buttonFind_clicked()
{
    QString str = ui->lineEdit->text();
    QString sql = QString("name = '%1'").arg(str);
    model->setFilter(sql);
    model->select();
}
