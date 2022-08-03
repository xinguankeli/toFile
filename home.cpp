#include "home.h"
#include "ui_home.h"
#include <QMessageBox>
#include <QPushButton>
#include "inputpassword.h"
#include "tools/utils.h"
Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    connect(ui->enterButton, &QPushButton::clicked, this, &Home::processLink);

}

Home::~Home()
{
    delete ui;
}

QString Home::getLocalDeviceNumber()
{
    return ui->deviceNumber->text();
}

QString Home::getTempPassword()
{
    return ui->tempPassword->text();
}

QString Home::getRemoteDeviceNumber()
{
    return ui->remoteDeviceNumber->text();
}
void Home::processLink()
{
    //获取此设备代码
    QString localNumber = this->getLocalDeviceNumber();
    //获取临时密码
    QString tempPassword = this->getTempPassword();
    //获取远程控制代码
    QString remoteNumber = this->getRemoteDeviceNumber();

    //判断远程控制代码是否是6位全数字

    if(remoteNumber.size() == 6 && Utils::getInstance()->isDigital(remoteNumber)){
        //发送服务器请求，将本地ip发送给服务器
        InputPassword inputPassword;
        inputPassword.setUserName(remoteNumber);
        if(inputPassword.exec() == 0){
            //获取对方唯一IP和Port成功

            //切换到文件列表界面，开始传输文件
        }
    }else{
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("远程设备代码不正确"));
    }
}
