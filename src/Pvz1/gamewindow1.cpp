#include "gamewindow1.h"

GameWindow1::GameWindow1(QWidget *parent) :
    QWidget(parent)
{
    //设置按钮和窗口
    b3.setParent(this);
    b3.setText("back to main");
    b3.setGeometry(100,250,150,50);
    setWindowTitle("普通无尽");

    //connect的四个参数分别是：1.信号发出者 2.发生的事件 3.信号接受者 4.要执行的动作，也就是槽函数
    //我们返回主窗口分为两步：1.点击b3发出一个mysolt信号 2.主窗口收到这个信号之后，调用主窗口的back1方法来实现返回主窗口（下面两行注释详细说明）
    //把b3按钮和sendsolt方法绑定，就是说按下按钮的时候会调用下面的sendslot方法，执行emit mysolt()，就是把这个信号发送出去的意思
    //在主窗口的30行的代码意思就是，一旦gamewin1发出了mysolt信号，就调用主窗口的back1函数
    connect(&b3,&QPushButton::clicked,this,&GameWindow1::sendslot);
}



void GameWindow1::sendslot()
{
    emit myslot();//就是发射一个信号的意思
}
