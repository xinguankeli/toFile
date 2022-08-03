#include "inputpassword.h"
#include "ui_inputpassword.h"
#include <QPushButton>
#include "tools/utils.h"
InputPassword::InputPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPassword)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &InputPassword::requestServer);
    timer = new QTimer();
    timer->setSingleShot(true);
    ui->label_2->setHidden(true);
    connect(timer, &QTimer::timeout, this, &InputPassword::hiddenLabel);
}

InputPassword::~InputPassword()
{
    delete ui;
}

void InputPassword::setUserName(QString username)
{
    this->username = username;
}

QString InputPassword::getRemoteIp()
{
    return "";
}

quint16 InputPassword::getRemotePort()
{
    return 0;
}

void InputPassword::requestServer()
{
    this->password = ui->lineEdit->text();
    //判断密码是不是6位数字和全是数字
    if(this->password.size() == 6 && Utils::getInstance()->isDigital(this->password)){
        //根据 username 和 password向服务器请求全局唯一IP和端口
        bool ret = false;
        //请求成功返回
        if(ret){
            //返回值为0
            this->done(0);
        }else{
            this->done(1);
        }
    }else{
        //密码输入的不对，重新输入
        ui->lineEdit->clear();
        timer->start(3000);
        ui->label_2->setHidden(false);

    }

}

void InputPassword::hiddenLabel()
{
    ui->label_2->setHidden(true);

}
