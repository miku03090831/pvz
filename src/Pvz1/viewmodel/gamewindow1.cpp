#include "gamewindow1.h"
/*建议可以尝试填充button的响应函数*/

QList<Zombie_Pic*> GameWindow1::z_pic;
QList<Sun_Pic*> GameWindow1::sunlight;

GameWindow1::GameWindow1(QWidget *parent) :
    QWidget(parent)
{
    //设置按钮和窗口
    QImage menu_background;
    this->resize(805,600);
    menu_background.load(":/image/res/background1.png");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(menu_background.scaled(size(), Qt::IgnoreAspectRatio,
                               Qt::SmoothTransformation)));
    setPalette(pal);
    //设置背景
    b3.setParent(this);
    shovel.setParent(this);
    shovel.setGeometry(446,0,70,72);
    shovel.setStyleSheet("QPushButton{border-image:url(:/image/res/shovel_box.png);}");
    b3.setGeometry(516,0,98,26);
    b3.setStyleSheet("QPushButton{border-image:url(:/image/res/back_btn.png);}");
    //上面是植物栏，铲子和退出的显示
    seedbox.setParent(this);
    //seedbox.move(0,0);


    int i=0,j=0;
    for(i=0;i<9;i++){   //图像显示及按钮
        for(j=0;j<5;j++){
            pic[i][j].move(50+81*i,100+98*j);
            box[i][j].setGeometry(40+81*i,80+98*j,81,98);
            box[i][j].setParent(this);
            box[i][j].setStyleSheet("QPushButton{background-color:transparent;}");

            pic[i][j].setParent(this);
            connect(&box[i][j],SIGNAL(clicked()),&signalmapper,SLOT(map()));    //进行信号的分发，增加一个参数
            signalmapper.setMapping(&box[i][j],i*10+j);

        }
    }

    /*用来测试zombie动画效果的代码
    Zombie_Pic *zombie1= new Zombie_Pic(this,0,0,0,2);
    Zombie_Pic *zombie2= new Zombie_Pic(this,2,1,0,2);
    z_pic.append(zombie1);
    z_pic.append(zombie2);
    */
    QTimer *zombieMove_timer1=new QTimer(this);//僵尸运动的计时器
    connect(zombieMove_timer1,SIGNAL(timeout()),this,SLOT(move_zombie()));
    zombieMove_timer1->start(1000);//timer设定每1s进行一次僵尸动画的位置运动

    QTimer *zombieGen_timer1=new QTimer(this);//僵尸生成计时器
    connect(zombieGen_timer1,SIGNAL(timeout()),this,SLOT(generate_zombie()));
    zombieGen_timer1->start(10000);

    /*Sun_Pic* sun1=new Sun_Pic(this, 400, 0, 525, 10000);
    Sun_Pic* sun2=new Sun_Pic(this, 700, 0, 525, 10000);
    sunlight.append(sun1);
    sunlight.append(sun2);*/
    QTimer *sun_timer1=new QTimer(this);
    connect(sun_timer1,SIGNAL(timeout()),this,SLOT(sun_move()));
    sun_timer1->start(20);

    QTimer *sun_timer2=new QTimer(this);
    connect(sun_timer2,SIGNAL(timeout()),this,SLOT(sun_down()));
    sun_timer2->start(2000);

    //connect的四个参数分别是：1.信号发出者 2.发生的事件 3.信号接受者 4.要执行的动作，也就是槽函数
    //我们返回主窗口分为两步：1.点击b3发出一个mysolt信号 2.主窗口收到这个信号之后，调用主窗口的back1方法来实现返回主窗口（下面两行注释详细说明）
    //把b3按钮和sendsolt方法绑定，就是说按下按钮的时候会调用下面的sendslot方法，执行emit mysolt()，就是把这个信号发送出去的意思
    //在主窗口的30行的代码意思就是，一旦gamewin1发出了mysolt信号，就调用主窗口的back1函数
    connect(&b3,&QPushButton::clicked,this,&GameWindow1::sendslot);
    connect(&shovel,&QPushButton::clicked,this,&GameWindow1::show_shovel);
    connect(&signalmapper,SIGNAL(mapped(int)),this,SLOT(putplant(int)));
    connect(&seedbox.seedboxmapper,SIGNAL(mapped(int)),this,SLOT(seedbox_clicked(int)));    //响应植物栏点击
    //用于响应点击
    normalpea.load(":/image/res/normalpea.png");
    snowpea.load(":/image/res/snowpea.png");
    peahit.load(":/image/res/PeaBulletHit.png");    //三个豌豆的图片
}

void GameWindow1::putplant(int place){  //点击格子时触发，用x*10+y表示位置，内容仅用于测试，需要填充
    int i=place/10;
    int j=place%10;
    switch(cursor_type){
    case 0:break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:if(pic[i][j].gettype()==0)
                pic[i][j].set_pic(cursor_type);
           cursorchange(0);
           break;
    case 7:if(pic[i][j].gettype()!=0)   pic[i][j].set_pic(0);cursorchange(0);break;
    default:cursor_type=0;break;
    }

    box[i][j].raise();
}

void GameWindow1::seedbox_clicked(int planttype){   //植物栏点击的响应事件
    cursorchange(planttype);
}

void GameWindow1::show_shovel(){//铲子响应
    cursorchange(7);
}



void GameWindow1::cursorchange(int cursortype){ //设置鼠标的样子，点击植物栏时改变，没写完，在p图，同时会改变中间变量（用于指明现在要放什么）
    QPixmap pixmap;
    QCursor cursor;
    switch (cursortype) {
    case 0:
        cursor_type=0;
        this->setCursor(Qt::ArrowCursor);   //正常图标
        break;
    case 1:
        pixmap.load(":/image/res/sunflower_cursor.png");    //太阳花
        cursor_type=1;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 2:
        pixmap.load(":/image/res/peanut_cursor.png");   //豌豆
        cursor_type=2;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 3:
        pixmap.load(":/image/res/snow_cursor.png"); //寒冰
        cursor_type=3;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 4:
        pixmap.load(":/image/res/repeater_cursor.png"); //双发
        cursor_type=4;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 5:
        pixmap.load(":/image/res/cherry_cursor.png");   //樱桃
        cursor_type=5;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 6:
        pixmap.load(":/image/res/wallnut_cursor.png");  //坚果墙
        cursor_type=6;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 7:
        pixmap.load(":/image/res/Shovel.png");  //铲子
        cursor_type=7;
        cursor=QCursor(pixmap,-1,-1);
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

void GameWindow1::starttimer(){
    this->timer.start();
}

void GameWindow1::move_zombie(){
    for(int i=0;i<z_pic.size();i++){
        z_pic[i]->Zombie_Walk();
        z_pic[i]->Zombie_Move(20);
    }//对zombie_pic list中所有僵尸执行运动，默认步长为20
}

void GameWindow1::generate_zombie(){
    int type, row;
    for(int i=0;i<1;i++){
        type=Gen_Rand(zombie_G_mode);
        row=Gen_Rand(5);
        z_pic.append(new Zombie_Pic(this,row,type,1,1));
    }
}

int GameWindow1::Gen_Rand(int upper){
    if(upper<=0)
        return 0;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return qrand()%upper;
}

void GameWindow1::sun_move(){
    int todel=-1;
    Sun_Pic* tmp;
    for(int i=0;i<sunlight.size();i++){
        sunlight[i]->duration+=20;
        if(sunlight[i]->duration>=10000){
            if(todel<0)
                todel=i;
        }
        sunlight[i]->sunmove(2);
    }
    if(todel>=0){
        tmp=sunlight.takeAt(todel);
        delete tmp;
    }
}

void GameWindow1::sun_down(){
    int sun_x=Gen_Rand(700);
    sun_x=(sun_x*sun_x)%700;
    sunlight.append(new Sun_Pic(this,sun_x,0,525,0,sunlight.size()));
    connect(sunlight[sunlight.size()-1],SIGNAL(clicked(int)),this,SLOT(sun_click(int)));
}

void GameWindow1::sun_click(int id){
    sunlight[id]->hide();
}
