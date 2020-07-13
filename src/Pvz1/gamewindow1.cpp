#include "gamewindow1.h"
/*建议可以尝试填充button的响应函数*/

GameWindow1::GameWindow1(QWidget *parent) :
    QWidget(parent)
{
    //设置按钮和窗口
    QImage menu_background;
    this->resize(805,600);
    menu_background.load(":/image/res/background2.png");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(menu_background.scaled(size(), Qt::IgnoreAspectRatio,
                               Qt::SmoothTransformation)));
    setPalette(pal);
    //设置背景

    b3.setParent(this);
    p0.setParent(this);
    p1.setParent(this);
    p2.setParent(this);
    p3.setParent(this);
    p4.setParent(this);
    p5.setParent(this);
    shovel.setParent(this);

    p0.setStyleSheet("QPushButton{border-image:url(:/image/res/sun_flower.png);}");
    p0.setGeometry(88,5,50,75);
    p1.setStyleSheet("QPushButton{border-image:url(:/image/res/peanut_box.png);}");
    p1.setGeometry(146,5,50,75);
    p2.setStyleSheet("QPushButton{border-image:url(:/image/res/snowpeanut_box.png);}");
    p2.setGeometry(204,5,50,75);
    p3.setStyleSheet("QPushButton{border-image:url(:/image/res/repeater_box.png);}");
    p3.setGeometry(262,5,50,75);
    p4.setStyleSheet("QPushButton{border-image:url(:/image/res/wallnut_box.png);}");
    p4.setGeometry(320,5,50,75);
    p5.setStyleSheet("QPushButton{border-image:url(:/image/res/cherry_box.png);}");
    p5.setGeometry(378,5,50,75);
    shovel.setGeometry(446,0,70,72);
    shovel.setStyleSheet("QPushButton{border-image:url(:/image/res/shovel_box.png);}");
    b3.setGeometry(516,0,98,26);
    b3.setStyleSheet("QPushButton{border-image:url(:/image/res/back_btn.png);}");
    //上面是植物栏，铲子和退出的显示

    int i=0,j=0;
    for(i=0;i<9;i++){   //图像显示及按钮
        for(j=0;j<5;j++){
            pic[i][j].move(50+81*i,100+98*j);
            box[i][j].setGeometry(40+81*i,80+98*j,81,98);
            box[i][j].setParent(this);
            box[i][j].setStyleSheet("QPushButton{background-color:transparent;}");

            pic[i][j].setParent(this);
            connect(&box[i][j],SIGNAL(clicked()),&signalmapper,SLOT(map()));
            signalmapper.setMapping(&box[i][j],i*10+j);

        }
    }

   //等待设置，需要先设置植物栏，准备放在植物栏右侧

    //connect的四个参数分别是：1.信号发出者 2.发生的事件 3.信号接受者 4.要执行的动作，也就是槽函数
    //我们返回主窗口分为两步：1.点击b3发出一个mysolt信号 2.主窗口收到这个信号之后，调用主窗口的back1方法来实现返回主窗口（下面两行注释详细说明）
    //把b3按钮和sendsolt方法绑定，就是说按下按钮的时候会调用下面的sendslot方法，执行emit mysolt()，就是把这个信号发送出去的意思
    //在主窗口的30行的代码意思就是，一旦gamewin1发出了mysolt信号，就调用主窗口的back1函数
    connect(&b3,&QPushButton::clicked,this,&GameWindow1::sendslot);
    connect(&p1,&QPushButton::clicked,this,&GameWindow1::plant1);
    connect(&signalmapper,SIGNAL(mapped(int)),this,SLOT(putplant(int)));
    //用于响应点击
}

void GameWindow1::putplant(int place){  //点击格子时触发，用x*10+y表示位置，内容仅用于测试，需要填充
    int i=place/10;
    int j=place%10;
    if(pic[i][j].gettype()==0)pic[i][j].set_pic(2);
    else pic[i][j].set_pic(0);
    box[i][j].raise();
}

void GameWindow1::plant1(){ //点击植物栏时触发，只写了一个，内容仅用于测试，需要补充
    cursorchange(2);
}

void GameWindow1::cursorchange(int cursortype){ //设置鼠标的样子，点击植物栏时改变，没写完，在p图，同时会改变中间变量（用于指明现在要放什么）
    switch (cursortype) {
    case 0:
        cursortype=0;
        this->setCursor(Qt::ArrowCursor);
        break;
    case 2:
        QPixmap pixmap(":/image/res/peanut_cursor.png");
        cursortype=2;
        QCursor cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    }
}


void GameWindow1::sendslot()
{
    emit myslot();//就是发射一个信号的意思
}

void GameWindow1::mousePressEvent(QMouseEvent *event){  //用于取消种植植物
    if(event->button()==Qt::RightButton){   //按右键时
        cursorchange(0);
    }else return ;
}

Plant_Pic::Plant_Pic(){
    this->hide();
    this->setMovie(&movie);
}

int Plant_Pic::set_pic(int type){   //显示植物，0为不显示，之后依次按照植物栏每种植物，在p图
    switch (type) {
    case 0:
        movie.stop();
        this->hide();
        this->type=0;
        return 0;
    case 1:
        movie.setFileName(":/image/res/Sunflower.gif");
        movie.start();
        this->type=1;
        this->show();
        return 0;
    case 2:
        movie.setFileName(":/image/res/Peashooter.gif");
        movie.start();
        this->type=2;
        this->show();
        return 0;
    }
}

int Plant_Pic::gettype(){
    return type;
}
