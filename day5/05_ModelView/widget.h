#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_buttonAdd_clicked();

    void on_buttonSure_clicked();

    void on_buttonCancle_clicked();

    void on_buttonDel_clicked();

    void on_buttonFind_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel * model;
};

#endif // WIDGET_H
