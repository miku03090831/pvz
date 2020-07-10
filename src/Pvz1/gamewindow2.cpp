#include "gamewindow2.h"

GameWindow2::GameWindow2(QWidget *parent) :
    QWidget(parent)
{
    b4.setParent(this);
    b4.setText("back to main");
    b4.setGeometry(100,150,150,50);
    setWindowTitle("传送带");


    connect(&b4,&QPushButton::clicked,this,&GameWindow2::sendslot);
}



void GameWindow2::sendslot()
{
    emit myslot();
}
