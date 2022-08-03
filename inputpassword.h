#ifndef INPUTPASSWORD_H
#define INPUTPASSWORD_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class InputPassword;
}

class InputPassword : public QDialog
{
    Q_OBJECT

public:
    explicit InputPassword(QWidget *parent = nullptr);
    ~InputPassword();

private:
    Ui::InputPassword *ui;
    QString username;
    QString password;
    QString m_remoteIp;
    quint16 m_remotePort;
    QTimer *timer;
public:
    void setUserName(QString username);
    //获取远端唯一IP、
    QString getRemoteIp();
    //获取远端唯一Port
    quint16 getRemotePort();
private slots:
    void requestServer();
    void hiddenLabel();
};

#endif // INPUTPASSWORD_H
