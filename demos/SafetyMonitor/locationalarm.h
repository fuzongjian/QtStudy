#ifndef LOCATIONALARM_H
#define LOCATIONALARM_H

#include <QWidget>

namespace Ui {
class LocationAlarm;
}

class LocationAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit LocationAlarm(QWidget *parent = 0);
    ~LocationAlarm();

private:
    Ui::LocationAlarm *ui;
};

#endif // LOCATIONALARM_H
