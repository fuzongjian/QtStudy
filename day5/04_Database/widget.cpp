#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 目前支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    // 添加mysql数据库       QSqlite 不支持auto_increment
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

    // 创建
//    QString sql = QString("create table student(id int primary key auto_increment,name varchar(255),age varchar(255),score varchar(255));");
//    QSqlQuery query;
//    query.exec(sql);


    // 批量插入
    //  odb风格   预处理语句
//    QSqlQuery query;// ? 相当于占位符
//    query.prepare("insert into student(name,age,score) values(?,?,?)");
//    // 给字段设置内容  list
//    QVariantList nameList;
//    nameList <<"xiaoming" <<"xiaoqiang"<<"xiaochao";
//    QVariantList ageList;
//    ageList << "11" <<"12"<<"13";
//    QVariantList scoreList;
//    scoreList <<"100"<<"101"<<"102";
//    // 给字段绑定相应的值， 按顺序绑定
//    query.addBindValue(nameList);
//    query.addBindValue(ageList);
//    query.addBindValue(scoreList);
//    // 预处理命令
//    query.execBatch();

    // oracle 风格
//    QSqlQuery query;// ? 相当于占位符
//    query.prepare("insert into student(name,age,score) values(:name,:age,:score)");
//    // 给字段设置内容  list
//    QVariantList nameList;
//    nameList <<"xiaoa" <<"xiaoq"<<"xiaoc";
//    QVariantList ageList;
//    ageList << "15" <<"16"<<"78";
//    QVariantList scoreList;
//    scoreList <<"110"<<"152"<<"147";
//    // 给字段绑定相应的值， 按顺序绑定
//    query.bindValue(":name",nameList);
//    query.bindValue(":age",ageList);
//    query.bindValue(":score",scoreList);
//    query.execBatch();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
    QString name = ui->lineEdit->text();
    QString sql = QString("delete from student where name = '%1';").arg(name);
    // 开启一个事物
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);
}

void Widget::on_buttonSure_clicked()
{
    // 确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_buttonCancle_clicked()
{
    // 回滚
    QSqlDatabase::database().rollback();
}

