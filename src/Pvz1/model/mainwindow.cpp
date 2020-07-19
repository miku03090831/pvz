#include "mainwindow.h"
#include "../viewmodel/gamewindow1.h"
#include "../viewmodel/gamewindow2.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QImage menu_background;
    this->resize(800,600);
    menu_background.load(":/image/res/menu.png");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(menu_background.scaled(size(), Qt::IgnoreAspectRatio,
                       Qt::SmoothTransformation)));
    setPalette(pal);
    //设置背景

    b1.setStyleSheet("QPushButton{background-color:transparent;}"
                     "QPushButton:pressed{border-image:url(:/image/res/quick.png);}");
    //第一个按钮的背景及按下效果

    b1.setParent(this);
    b1.setGeometry(29,402,162,113);  //位置大小

    b2.setStyleSheet("QPushButton{background-color:transparent;}"
                     "QPushButton:pressed{border-image:url(:/image/res/mode.png);}");
    //第二个按钮的背景及按下效果

    b2.setParent(this);
    b2.setGeometry(241,160,297,141);  //位置大小


    b5.setStyleSheet("QPushButton{background-color:transparent;}"
                     "QPushButton:pressed{border-image:url(:/image/res/quit.png);}");
    //第五个按钮的背景及按下效果
    b5.setParent(this);
    b5.setGeometry(627,440,123,63);  //位置大小

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
    flag=1;
    gamewin1.show();
    flag=1;
    gamewin1.starttimer(); //计时器开始计时
    this->hide();
}

void MainWindow::back1()
{
    this->show();
    gamewin1.hide();

}

void MainWindow::game2()
{
    flag=2;
    gamewin2.show();
    flag=2;
    this->hide();
}
void MainWindow::back2()
{
    this->show();
    gamewin2.hide();
}

