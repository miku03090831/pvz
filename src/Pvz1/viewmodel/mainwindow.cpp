#include "mainwindow.h"
#include "gamewindow1.h"


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


    b5.setStyleSheet("QPushButton{background-color:transparent;}"
                     "QPushButton:pressed{border-image:url(:/image/res/quit.png);}");
    //第五个按钮的背景及按下效果
    b5.setParent(this);
    b5.setGeometry(627,440,123,63);  //位置大小

    this->setWindowTitle("main");

    connect(&b5,&QPushButton::clicked,this,&MainWindow::close);
    connect(&b1,&QPushButton::clicked,this,&MainWindow::game1);


}



MainWindow::~MainWindow()
{
}


void MainWindow::game1()
{
    flag=1;
    gamewin1=new GameWindow1;
    gamewin1->show();
    flag=1;
    this->hide();
    connect(gamewin1,&GameWindow1::myslot,this,&MainWindow::back1);
    connect(gamewin1,&GameWindow1::again,this,&MainWindow::win1again);
    connect(gamewin1,&GameWindow1::backtomenu,this,&MainWindow::win1backtomenu);

}

void MainWindow::back1()
{
    this->show();
    delete gamewin1;

}



void MainWindow::win1again(){
    delete gamewin1;
    gamewin1=new GameWindow1;
    gamewin1->show();
    //需要更改
}

void MainWindow::win1backtomenu(){
    this->show();
    delete gamewin1;
    //需要更改
}
