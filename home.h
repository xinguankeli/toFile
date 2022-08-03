#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "inputpassword.h"
namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
public:
    //获取此设备代码
    QString getLocalDeviceNumber();
    //获取临时密码
    QString getTempPassword();
    //获取远程设备链接码
    QString getRemoteDeviceNumber();
private slots:
    void processLink();
};

#endif // HOME_H
