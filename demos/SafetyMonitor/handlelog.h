#ifndef HANDLELOG_H
#define HANDLELOG_H

#include <QWidget>

namespace Ui {
class HandleLog;
}

class HandleLog : public QWidget
{
    Q_OBJECT

public:
    explicit HandleLog(QWidget *parent = 0);
    ~HandleLog();

private:
    Ui::HandleLog *ui;
};

#endif // HANDLELOG_H
