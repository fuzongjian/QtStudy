#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "domxml.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 开始 车辆管理界面
    on_actionCar_triggered();
    connectDB();
    initData();
    DomXML::createXML("../demo.xml");
    QStringList list;
    list <<"二汽神龙" <<"毕加索" <<"39" <<"1"<<"39";
    DomXML::appendXML("../demo.xml",list);


    QStringList fList,bList,pList,nList,tList;
    DomXML::readXML("../demo.xml",fList,bList,pList,nList,tList);
    for(int i = 0; i < fList.size(); i ++){
        QString str = QString("%1:%2:卖出了%3,单价:%4,总价:%5")
                .arg(fList.at(i))
                .arg(bList.at(i))
                .arg(nList.at(i))
                .arg(pList.at(i))
                .arg(tList.at(i));
        qDebug()<<str.toUtf8().data();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
// 车辆管理
void MainWindow::on_actionCar_triggered()
{
    ui->label->setText("车辆管理");
    ui->stackedWidget->setCurrentWidget(ui->car);
}

void MainWindow::on_actionCalc_triggered()
{
    ui->label->setText("销售统计");
    ui->stackedWidget->setCurrentWidget(ui->calc);
}
void MainWindow::connectDB(){
    //
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setDatabaseName("car");
    db.setPassword("123456");
    if(db.open() == false){
        QMessageBox::warning(this,"数据库打开失败",db.lastError().text());
        return;
    }
}
void MainWindow::initData(){
    QSqlQueryModel * queryModel = new QSqlQueryModel(this);//新建模型
    queryModel->setQuery("select name from factory");// sql语句
    ui->comboBoxFactory->setModel(queryModel);

    ui->labelLast->setText("0");// 剩余数量
    ui->lineEditTotal->setEnabled(false);// 金额

}
// 厂家下拉槽函数
void MainWindow::on_comboBoxFactory_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "请选择厂家"){
        // 内容清空
        ui->comboBoxBrand->clear();// 品牌下拉清空
        ui->lineEditPrice->clear();// 报价清空
        ui->labelLast->setText("0");
        ui->lineEditTotal->clear();
        ui->spinBox->setValue(0);// 数量选择框
        ui->spinBox->setEnabled(false);
        ui->buttonSure->setEnabled(false);
    }else{
        ui->comboBoxBrand->clear();
        QSqlQuery query;
        QString sql = QString("select name from brand where factory = '%1'").arg(arg1);
        query.exec(sql);
        while(query.next()){
            QString name = query.value(0).toString();
            ui->comboBoxBrand->addItem(name);
        }
        ui->spinBox->setEnabled(true);
    }
}

void MainWindow::on_comboBoxBrand_currentIndexChanged(const QString &arg1)
{

    QString sql = QString("select price,last from brand where factory = '%1' and name = '%2'").arg(ui->comboBoxFactory->currentText())
            .arg(arg1);
    QSqlQuery query;
    query.exec(sql);
    while(query.next()){
        // 报价
       QString price = query.value("price").toString();
       QString last = query.value("last").toString();

       ui->lineEditPrice->setText(price);
       ui->labelLast->setText(last);
    }

}
// 数量选择框的槽函数
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(arg1 == 0){
        ui->buttonSure->setEnabled(false);
    }else{
        ui->buttonSure->setEnabled(true);
    }

    // 更新剩余数量
    // 获取数据库剩余数量
    QString sql = QString("select sum,last from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory->currentText()).arg(ui->comboBoxBrand->currentText());
    QSqlQuery query;
    query.exec(sql);
    QString last;
    while(query.next()){
        last = query.value("last").toString();
    }
    if(arg1 > last.toInt()){
        ui->spinBox->setMaximum(last.toInt());
        return;// 如果选择的数目大于剩余数目，中断
    }
    int tempNum = last.toInt() - arg1;
    ui->labelLast->setText(QString::number(tempNum));// 剩余数量

    // 金额
    int price = ui->lineEditPrice->text().toInt();// 报价
    int sum = price * arg1;
    ui->lineEditTotal->setText(QString::number(sum));




}

void MainWindow::on_buttonSure_clicked()
{
    // 销售数量
    int num = ui->spinBox->value();
    // 剩余
    int last = ui->labelLast->text().toInt();
    QString sql = QString("select sell from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory->currentText()).arg(ui->comboBoxBrand->currentText());
    int sell;
    QSqlQuery query;
    query.exec(sql);
    while (query.next()) {
        sell = query.value("sell").toString().toInt();
    }


    // 更新数据库
    sell += num;
    sql = QString("update brand set sell = '%1',last = '%2'where factory = '%3' and name = '%4'")
            .arg(QString::number(sell)).arg(QString::number(last))
            .arg(ui->comboBoxFactory->currentText())
            .arg(ui->comboBoxBrand->currentText());
    bool status = query.exec(sql);
    if(status == false){
        QMessageBox::warning(this,"数据库打开失败",query.lastError().text());
    }


    // 把确认后的数据，更新到xml中



    ui->buttonSure->setEnabled(false);
    on_buttonCancle_clicked();
}

void MainWindow::on_buttonCancle_clicked()
{
    ui->comboBoxFactory->setCurrentIndex(0);
}
