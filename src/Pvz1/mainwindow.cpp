#include "mainwindow.h"
#include "gamewindow1.h"
#include "gamewindow2.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    b1.setParent(this);
    b1.setGeometry(100,100,150,50);  //位置大小
    b1.setText("普通无尽");

    b2.setParent(this);
    b2.setGeometry(100,200,150,50);  //位置大小
    b2.setText("传送带");

    b5.setParent(this);
    b5.setGeometry(100,300,150,50);
    b5.setText("退出游戏");

    this->setWindowTitle("main");



    connect(&b5,&QPushButton::clicked,this,&MainWindow::close);
    connect(&b1,&QPushButton::clicked,this,&MainWindow::game1);
    connect(&b2,&QPushButton::clicked,this,&MainWindow::game2);

    connect(&gamewin1,&GameWindow1::myslot,this,&MainWindow::back1);
    connect(&gamewin2,&GameWindow2::myslot,this,&MainWindow::back2);

}

MainWindow::~MainWindow()
{
}


void MainWindow::game1()
{
    gamewin1.show();
    gamewin1.resize(500,500);
    this->hide();
}

void MainWindow::back1()
{
    this->show();
    gamewin1.hide();

}

void MainWindow::game2()
{
    gamewin2.show();
    gamewin2.resize(500,500);
    this->hide();
}
void MainWindow::back2()
{
    this->show();
    gamewin2.hide();
}
