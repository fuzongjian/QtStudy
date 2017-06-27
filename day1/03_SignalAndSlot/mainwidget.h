#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void myslot();
    void changeWin();
//    void dealSub();
//    void dealSlot(int,QString);
public slots:
    void dealSub();
    void dealSlot(int,QString);
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget sub;

};

#endif // MAINWIDGET_H
