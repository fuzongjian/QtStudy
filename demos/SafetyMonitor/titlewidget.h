#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "toolbutton.h"
namespace Ui {
class TitleWidget;
}

class TitleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();
    QList<ToolButton *> button_list;
private:
    Ui::TitleWidget *ui;
protected:
    void paintEvent(QPaintEvent *);
protected://鼠标移动窗口
    QPoint press_point;
    bool is_move;
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private slots:
    void turnPage(QString current_page);
signals:
    void showMin();
    void closeWindow();
};

#endif // TITLEWIDGET_H
