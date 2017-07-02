#ifndef TOOL_BUTTON_H
#define TOOL_BUTTON_H

#include <QToolButton>
#include <QtGui>
class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolButton(QWidget *parent = 0);
    void setBgImage(QString pic_name);
    void setMousePress(bool mouse_press);
protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void painterInfo(int top_color, int middle_color, int bottom_color);
public:

    bool mouse_over;
    bool mouse_press;
signals:

public slots:
};

#endif // TOOLBUTTON_H
