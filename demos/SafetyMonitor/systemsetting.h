#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QWidget>

namespace Ui {
class SystemSetting;
}

class SystemSetting : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSetting(QWidget *parent = 0);
    ~SystemSetting();

private:
    Ui::SystemSetting *ui;
};

#endif // SYSTEMSETTING_H
