#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "monitormanager.h"
#include "locationalarm.h"
#include "alarmrecord.h"
#include "handlelog.h"
#include "systemsetting.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void changeView_one();
    void changeView_two();
    void changeView_three();
    void changeView_four();
    void changeView_five();
};

#endif // MAINWINDOW_H
