#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
namespace Ui {
class TitleWidget;
}

class TitleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

private:
    Ui::TitleWidget *ui;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // TITLEWIDGET_H
