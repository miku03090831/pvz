#include "gamewindow2.h"

GameWindow2::GameWindow2(QWidget *parent) :
    QWidget(parent)
{
    QImage menu_background;
    this->resize(805,600);
    menu_background.load(":/image/res/background1.png");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(menu_background.scaled(size(), Qt::IgnoreAspectRatio,
                               Qt::SmoothTransformation)));
    setPalette(pal);
    //设置背景

    b4.setParent(this);
    //等待设置，需要先设置植物栏，准备放在植物栏右侧


    connect(&b4,&QPushButton::clicked,this,&GameWindow2::sendslot);
}



void GameWindow2::sendslot()
{
    emit myslot();
}
