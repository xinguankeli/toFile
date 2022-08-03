#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString::fromUtf8("toFile"));
    init();
    setCentralWidget(worldWidget);
    setFixedSize(500, 300);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    home = new Home();
    worldWidget = new QStackedWidget();
    worldWidget->addWidget(home);
    worldWidget->setCurrentIndex(0);
}



