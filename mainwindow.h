#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "home.h"
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //首页
    Home *home;
    //主栈
    QStackedWidget *worldWidget;


private:
    void init();

private slots:

};
#endif // MAINWINDOW_H
