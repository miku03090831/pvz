﻿#include "gamewindow1.h"
#include <QDebug>
/*建议可以尝试填充button的响应函数*/

QList<Zombie_Pic*> GameWindow1::z_pic;
QList<Sun_Pic*> GameWindow1::sunlight;
QList<Pea_Pic*> GameWindow1::p_pic;

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

    gaover_pic.setParent(this);
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

    for(i=0;i<6;i++){   //植物栏按钮
        plant_box[i].setParent(this);
        plant_box[i].setGeometry(88+60*i,5,50,75);
        plant_box[i].setStyleSheet("QPushButton{background-color:transparent;}");
        connect(&plant_box[i],SIGNAL(clicked()),&boxmapper,SLOT(map()));
        boxmapper.setMapping(&plant_box[i],i+1);
        plant_box[i].raise();
    }

    /*用来测试zombie动画效果的代码
    Zombie_Pic *zombie1= new Zombie_Pic(this,0,0,0,2);
    Zombie_Pic *zombie2= new Zombie_Pic(this,2,1,0,2);
    z_pic.append(zombie1);
    z_pic.append(zombie2);
    */
    connect(&zombieGen_timer1,SIGNAL(timeout()),this,SLOT(generate_zombie()));


    connect(&zombieMove_timer1,SIGNAL(timeout()),this,SLOT(move_zombie()));
    zombieGen_timer1.start(4000);
    zombieMove_timer1.start(187);//timer设定每0.2s进行一次僵尸动画的位置运动

    peaMove_timer.start(25);
    connect(&peaMove_timer,SIGNAL(timeout()),this,SLOT(move_pea()));

    /*Sun_Pic* sun1=new Sun_Pic(this, 400, 0, 525, 10000);
    Sun_Pic* sun2=new Sun_Pic(this, 700, 0, 525, 10000);
    sunlight.append(sun1);
    sunlight.append(sun2);*/
    connect(&sun_timer1,SIGNAL(timeout()),this,SLOT(sun_move()));
    sun_timer1.start(20);

    connect(&sun_timer2,SIGNAL(timeout()),this,SLOT(sun_down()));
    sun_timer2.start(7500);

    connect(&alive_check,SIGNAL(timeout()),this,SLOT(zombie_hide()));
    connect(&alive_check,SIGNAL(timeout()),this,SLOT(plant_death()));
    connect(&alive_check,SIGNAL(timeout()),this,SLOT(set_sun_num()));
    connect(&alive_check,SIGNAL(timeout()),this,SLOT(pea_hide()));
    alive_check.start(100);

    connect(&plant_act,SIGNAL(timeout()),this,SLOT(act_plant()));
    connect(&plant_act,SIGNAL(timeout()),this,SLOT(act_pea()));
    plant_act.start(20);


    //connect的四个参数分别是：1.信号发出者 2.发生的事件 3.信号接受者 4.要执行的动作，也就是槽函数
    //我们返回主窗口分为两步：1.点击b3发出一个mysolt信号 2.主窗口收到这个信号之后，调用主窗口的back1方法来实现返回主窗口（下面两行注释详细说明）
    //把b3按钮和sendsolt方法绑定，就是说按下按钮的时候会调用下面的sendslot方法，执行emit mysolt()，就是把这个信号发送出去的意思
    //在主窗口的30行的代码意思就是，一旦gamewin1发出了mysolt信号，就调用主窗口的back1函数
    connect(&b3,&QPushButton::clicked,this,&GameWindow1::sendslot);
    connect(&shovel,&QPushButton::clicked,this,&GameWindow1::show_shovel);
    connect(&signalmapper,SIGNAL(mapped(int)),this,SLOT(putplant(int)));
    connect(&boxmapper,SIGNAL(mapped(int)),this,SLOT(seedbox_clicked(int)));    //响应植物栏点击
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
    case 6:if(pic[i][j].gettype()==0){
            pic[i][j].set_pic(cursor_type);
            sunlight_sub();
            append_plant(i,j);
        }
           cursorchange(0);          
           break;
    case 7:if(pic[i][j].gettype()!=0){
            delete_plant(i,j);
            pic[i][j].set_pic(0);
        }
        cursorchange(0);
        break;
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
        if(Sunlight_num<50)
            return;
        pixmap.load(":/image/res/sunflower_cursor.png");    //太阳花
        cursor_type=1;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 2:
        if(Sunlight_num<100)
            return;
        pixmap.load(":/image/res/peanut_cursor.png");   //豌豆
        cursor_type=2;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 3:
        if(Sunlight_num<175)
            return;
        pixmap.load(":/image/res/snow_cursor.png"); //寒冰
        cursor_type=3;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 4:
        if(Sunlight_num<200)
            return;
        pixmap.load(":/image/res/repeater_cursor.png"); //双发
        cursor_type=4;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 5:
        if(Sunlight_num<150)
            return;
        pixmap.load(":/image/res/cherry_cursor.png");   //樱桃
        cursor_type=5;
        cursor=QCursor(pixmap,-1,-1);
        setCursor(cursor);
        break;
    case 6:
        if(Sunlight_num<50)
            return;
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


void GameWindow1::move_zombie(){
    for(int i=0;i<z_pic.size();i++){
        zombies[i]->act();
        if(!zombies[i]->moving){
            if(zombies[i]->attack_flag==0)
            {
                if(zombies[i]->froze_flag==1)
                    z_pic[i]->setFroze(1);
                z_pic[i]->Zombie_Attack();
                zombies[i]->attack_flag=1;
            }
        }
        else{
            if(zombies[i]->iced)
            {
                if(zombies[i]->attack_flag==1)
                {
                    if(zombies[i]->froze_flag==0)
                    {
                        z_pic[i]->Zombie_Froze();
                        zombies[i]->froze_flag=1;
                    }
                    zombies[i]->attack_flag=0;
                }
                if(zombies[i]->froze_flag==0)
                {
                    z_pic[i]->Zombie_Froze();
                    zombies[i]->froze_flag=1;
                }
                z_pic[i]->Zombie_Move(2);
            }
            else
            {
                if(zombies[i]->attack_flag==1)
                {
                    z_pic[i]->Zombie_Walk();
                    zombies[i]->attack_flag=0;
                }
                z_pic[i]->Zombie_Move(4);
            }
            if(z_pic[i]->getx()+101<0 && z_pic[i]->del==0){
                gameover();
                return ;
            }
            //zombies[i]->posX=z_pic[i]->getx();
            zombies[i]->move(z_pic[i]->getx(),z_pic[i]->gety());
        }
    }//对zombie_pic list中所有僵尸执行运动，默认步长为20
    for(int i=0;i<6;i++)
    {
        plant_box[i].raise();
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<5;j++)
        {
            box[i][j].raise();
        }
    }
    shovel.raise();
    b3.raise();
    Sun_Pic* s;
    foreach(s,sunlight)
    {
        s->raise();
    }
}

void GameWindow1::generate_zombie(){
    static int count=0;
    int type, row;
    if(count%5<zombie_G_speed){
        type=Gen_Rand(zombie_G_mode);
        row=Gen_Rand(5);
        z_pic.append(new Zombie_Pic(this,row,type,3,3));
        if(type==0)
            zombies.append(new SimpleZombie(this));
        else if(type==1)
            zombies.append(new ConeheadZombie(this));
        else
            zombies.append(new BucketZombie(this));
        zombies[zombies.size()-1]->row=row;
        ZombieNum[row]++;
    }
    count++;
    if(zombies.size()>=10)
        zombie_G_mode=(zombie_G_mode>2)?zombie_G_mode:zombie_G_mode+1;
    else if(zombies.size()>=5)
        zombie_G_mode=(zombie_G_mode>1)?zombie_G_mode:zombie_G_mode+1;
    if(zombies.size()<=20)
        zombie_G_speed=zombies.size()/5+1;


//    for(int i=0;i<5;i++)
//    {
//        qDebug()<<ZombieNum[i]<<" ";
//    }
//    qDebug()<<endl;
}

int GameWindow1::Gen_Rand(int upper){
    if(upper<=0)
        return 0;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return qrand()%upper;
}

void GameWindow1::sun_move(){
    for(int i=0;i<sunlight.size();i++){
        sunlight[i]->duration+=20;
        if(sunlight[i]->duration>=10000){
            sunlight[i]->hide();
        }
        sunlight[i]->sunmove(2);
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
    Sunlight_num+=25;
}

void GameWindow1::append_plant(int col, int row){
    switch (cursor_type) {
    case 1:plants.append(new SunFlower(this));break;
    case 2:plants.append(new SinglePea(this));break;
    case 3:plants.append(new IcePea(this));break;
    case 4:plants.append(new DoublePea(this));break;
    case 5:plants.append(new Cherry(this));break;
    case 6:plants.append(new WallNut(this));break;
    default:return;
    }
    plants[plants.size()-1]->col=col;
    plants[plants.size()-1]->row=row;
    plants[plants.size()-1]->setGeometry(50+81*col,100+98*row,81,98);
}
//把植物加进plants

void GameWindow1::delete_plant(int col, int row){
    int index=-1;
    for(int i=0;i<plants.size();i++){
        if(plants[i]->col==col&&plants[i]->row==row){
            index=i;
            break;
        }
    }
    if(index>=0){
        Plant* tmp=plants.takeAt(index);
        delete tmp;
    }
}
//删除plants中的植物

void GameWindow1::gameover(){
    //添加计时器停止
    sun_timer1.stop();
    sun_timer2.stop();
    alive_check.stop();
    plant_act.stop();
    peaMove_timer.stop();
    zombieMove_timer1.stop();
    zombieGen_timer1.stop();
    gaover_pic.show();
    gaover_pic.raise();
    for(int i=0;i<zombies.size();i++){
        if(zombies[i]->alive)
        {
            z_pic[i]->stopmovie();
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<5;j++){
            pic[i][j].stopmovie();
        }
    }
    for(int i=0;i<sunlight.size();i++){
        sunlight[i]->stopmovie();
    }
    this->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    connect(&gaover_pic.again,SIGNAL(clicked()),this,SLOT(win1again()));
    connect(&gaover_pic.backtomenu,SIGNAL(clicked()),this,SLOT(win1backtomenu()));
}

void GameWindow1::win1again(){
    emit again();
}

void GameWindow1::win1backtomenu(){
    emit backtomenu();
}
void GameWindow1::zombie_hide(){
    for(int i=0;i<zombies.size();i++){
        if(!zombies[i]->alive && zombies[i]->flag==0)
        {
            zombies[i]->hide();
            z_pic[i]->del=1;
            z_pic[i]->hide();
            zombies[i]->flag=1;
            ZombieNum[zombies[i]->row]--;
        }
    }
}//隐藏已死亡僵尸

void GameWindow1::pea_hide(){
    for(int i=0;i<shootpeas.size();i++){
        if(!shootpeas[i]->alive)
        {
            p_pic[i]->hide();
        }
    }
}//隐藏击中目标后的豌豆

void GameWindow1::plant_death(){
    int index=-1;
    for(int i=0;i<plants.size();i++){
        if(!plants[i]->alive){
            index=i;
            break;
        }
    }
    if(index>=0){
        pic[plants[index]->col][plants[index]->row].set_pic(0);
        Plant* tmp=plants.takeAt(index);
        delete tmp;
    }
}//检查plant是否被吃

void GameWindow1::set_sun_num(){
    seedbox.SunNumChange(Sunlight_num);
}

void GameWindow1::sunlight_sub(){
    int value=0;
    switch(cursor_type){
    case 1:value=50;break;
    case 2:value=100;break;
    case 3:value=175;break;
    case 4:value=200;break;
    case 5:value=150;break;
    case 6:value=50;break;
    default:break;
    }
    Sunlight_num-=value;
}//种植植物，阳光减少

void GameWindow1::act_plant(){
    for(int i=0;i<plants.size();i++){
        plants[i]->act();
        if(plants[i]->state==1){
            Pea *p=new Pea;
            p->row=plants[i]->row;
            shootpeas.append(p);
            Normal_Pea *p_p=new Normal_Pea(this,plants[i]->col,plants[i]->row,5);
            p_pic.append(p_p);
        }
        else if(plants[i]->state==2){
            Ice *p=new Ice;
            p->row=plants[i]->row;
            shootpeas.append(p);
            Snow_Pea *p_p=new Snow_Pea(this,plants[i]->col,plants[i]->row,10);
            p_pic.append(p_p);
        }
        else if(plants[i]->state==-1){
            sunlight.append(new Sun_Pic(this,plants[i]->x()+30,plants[i]->y()-15,plants[i]->y()+5,0,sunlight.size()));
            connect(sunlight[sunlight.size()-1],SIGNAL(clicked(int)),this,SLOT(sun_click(int)));
        }
    }
}//射出豌豆的设定

void GameWindow1::act_pea()
{
    ShootPea *spea;
    foreach(spea,shootpeas)
    {
        spea->act();
    }
}

void GameWindow1::move_pea(){
    for(int i=0;i<p_pic.size();i++)
    {
        p_pic[i]->Pea_Move();
        shootpeas[i]->move(p_pic[i]->x(),p_pic[i]->y());
    }
}

GameWindow1::~GameWindow1(){
    qDeleteAll(plants.begin(),plants.end());
    plants.clear();
    qDeleteAll(shootpeas.begin(),shootpeas.end());
    shootpeas.clear();
    qDeleteAll(zombies.begin(),zombies.end());
    zombies.clear();
    qDeleteAll(z_pic.begin(),z_pic.end());
    z_pic.clear();
    qDeleteAll(sunlight.begin(),sunlight.end());
    sunlight.clear();
    qDeleteAll(p_pic.begin(),p_pic.end());
    p_pic.clear();
}
