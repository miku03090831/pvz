#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "gamewindow1.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

//下面五个函数均为槽函数，
//其中 back1和back2接受的是**两个游戏窗口**发出的信号，具体说明可见游戏窗口的cpp内注释
//剩下的三个函数接受的都是主窗口的**按钮**发出的信号，使用方法可见主窗口cpp如何调用
    void back1();//从 普通无尽 返回 主窗口 的槽函数
    void game1();//进入 普通无尽模式 的槽函数
    void back2();//从 传送带模式 返回主窗口的槽函数
    void game2();//进入 传送带模式 的槽函数
    void exit();//退出游戏的槽函数
    void win1again();
    void win1backtomenu();
    QWidget* GetWin();
    int flag=1;
    GameWindow1 *gamewin1;//普通无尽窗口的对象

private:
    QPushButton b1,b5;//b1是进入普通无尽的按钮，b2是进入传送带的按钮，b5是退出游戏的按钮



};

#endif // MAINWINDOW_H
