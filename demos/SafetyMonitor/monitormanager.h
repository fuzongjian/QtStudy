#ifndef MONITORMANAGER_H
#define MONITORMANAGER_H

#include <QWidget>

namespace Ui {
class MonitorManager;
}

class MonitorManager : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorManager(QWidget *parent = 0);
    ~MonitorManager();

private:
    Ui::MonitorManager *ui;
};

#endif // MONITORMANAGER_H
