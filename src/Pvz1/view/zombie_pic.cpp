#include"zombie_pic.h"

Zombie_Pic::Zombie_Pic(QWidget* parent, int y, int type, int interval, int movetime){   //四个参数，分别为父窗口，用this就行，y出生的行0-4，type 0-2，分别为普通僵尸，路障，铁桶
    this->setParent(parent);                                                            //interval是每次前移间隔的时间，movetime是每次走动持续的时间，例如我设置interval=7，movetime=3
    headlabel.setParent(parent);                                                        //则每10次调用move函数，前七次不进行走动，后三次每次走动speed的像素长度
    this->resize(102,144);
    movie.setCacheMode(QMovie::CacheAll);
    switch (type) {
    case 0:
        movie.setFileName(":/image/res/Zombie2.gif");
        this->type=0;
        break;
    case 1:
        movie.setFileName(":/image/res/ConeheadZombie.gif");
        this->type=1;
        break;
    case 2:
        movie.setFileName(":/image/res/BucketheadZombie.gif");
        this->type=2;
        break;
    }
    this->interval=interval;
    headmovie.setFileName(":/image/res/ZombieHead.gif");
    headlabel.setMovie(&headmovie);
    this->setMovie(&movie);
    this->time=0;
    headlabel.hide();
    movie.start();
    froze=0;
    this->movetime=movetime;
    this->move(800,20+98*y);//为了让僵尸出场看起来自然一些把初始坐标改成了800,真正踩上草坪的坐标大概在730左右
    this->dead=0;
    this->del=0;
    this->attack=0;
    this->show();
}

void Zombie_Pic::Zombie_Walk(){ //将僵尸调整为走动状态，只改变图像
    this->attack=0;
    this->move(this->x()+10,this->y());
    movie.stop();
    if(froze){
        switch (type) {
        case 0:
            movie.setFileName(":/image/res/Zombie2_Froze.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombie_Froze.gif");
            break;
        case 2:
            movie.setFileName(":image/res/BucketheadZombie_Froze.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHead_Froze.gif");
            break;
        }
    }else{
        switch (type) {
        case 0:
            movie.setFileName(":/image/res/Zombie2.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombie.gif");
            break;
        case 2:
            movie.setFileName(":/image/res/BucketheadZombie.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHead.gif");
            break;
        }
    }
    movie.start();
}

void Zombie_Pic::Zombie_deFroze(){
    froze=0;
    movie.stop();
    int now_frame=movie.currentFrameNumber();
    if(now_frame!=movie.frameCount()-1)now_frame++;
    else now_frame=0;
    if(attack){
        switch(type){
        case 0:
            movie.setFileName(":/image/res/ZombieAttack.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombieAttack.gif");
            break;
        case 2:
            movie.setFileName(":/image/res/BucketheadZombieAttack.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHeadAttack.gif");
            break;
        }
    }else{
        switch (type) {
        case 0:
            movie.setFileName(":/image/res/Zombie2.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombie.gif");
            break;
        case 2:
            movie.setFileName(":image/res/BucketheadZombie.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHead.gif");
            break;
        }
    }
    movie.jumpToFrame(now_frame);
    movie.start();
}

void Zombie_Pic::Zombie_Move(int speed){    //僵尸移动
    if(time>=interval){
        this->move(this->x()-speed,this->y());
    }
    time++;
    if(time==interval+movetime){
        time=0;
    }
}

void Zombie_Pic::Zombie_Attack(){   //改变为攻击状态
    movie.stop();
    this->move(this->x()-10,this->y());
    this->attack=1;
    if(froze){
        switch(type){
        case 0:
            movie.setFileName(":/image/res/ZombieAttack_Froze.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombieAttack_Froze.gif");
            break;
        case 2:
            movie.setFileName(":/image/res/BucketheadZombieAttack_Froze.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHeadAttack_Froze.gif");
            break;
        }
    }else{
        switch(type){
        case 0:
            movie.setFileName(":/image/res/ZombieAttack.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombieAttack.gif");
            break;
        case 2:
            movie.setFileName(":/image/res/BucketheadZombieAttack.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHeadAttack.gif");
                break;
        }
    }
    movie.start();
    this->show();
}

void Zombie_Pic::Zombie_Die(){  //死亡，死亡时僵尸应该处于LostHead状态
    movie.stop();
    this->dead=1;
    this->move(this->x()-78,this->y());
    this->resize(200,150);
    movie.setFileName(":/image/res/ZombieDie.gif");
    connect(&movie,SIGNAL(frameChanged(int)),this,SLOT(frameevent(int)));
    movie.start();
}

void Zombie_Pic::Zombie_Change(){   //路障/铁桶僵尸变为普通僵尸
    movie.stop();
    int now_frame=movie.currentFrameNumber();
    if(now_frame!=movie.frameCount()-1)now_frame++;
    else now_frame=0;
    if(froze){
        if(attack)movie.setFileName(":/image/res/ZombieAttack_Froze.gif");
        else movie.setFileName(":/image/res/Zombie2_Froze.gif");
    }else{
        if(attack)movie.setFileName(":/image/res/ZombieAttack.gif");
        else movie.setFileName(":/image/res/Zombie2.gif");
    }
    this->type=0;
    movie.jumpToFrame(now_frame);
    movie.start();
}

void Zombie_Pic::Zombie_LostHead(){ //僵尸头掉了，保持原来的动画状态（行走/攻击）
    movie.stop();
    int now_frame=movie.currentFrameNumber();
    if(now_frame!=movie.frameCount()-1)now_frame++;
    else now_frame=0;
    headlabel.move(this->x()+24,this->y()-1);
    this->type=3;
    if(froze){
        switch (attack) {
        case 0:
             movie.setFileName(":/image/res/ZombieLostHead_Froze.gif");
             break;
        case 1:
            movie.setFileName(":/image/res/ZombieLostHeadAttack_Froze.gif");
            break;
        }
    }else{
        switch (attack) {
        case 0:
             movie.setFileName(":/image/res/ZombieLostHead.gif");
             break;
        case 1:
            movie.setFileName(":/image/res/ZombieLostHeadAttack.gif");
            break;
        }
    }
    movie.start();
    movie.jumpToFrame(now_frame);
    headmovie.start();
    connect(&headmovie,SIGNAL(frameChanged(int)),this,SLOT(headevent(int)));
    this->show();
    headlabel.show();
}

void Zombie_Pic::Zombie_Burn(){ //被烧死，之后会添加消除图像的函数
    movie.stop();
    this->dead=1;
    movie.setFileName(":/image/res/BurnDie.gif");
    movie.start();
}

Zombie_Pic::~Zombie_Pic(){
    disconnect(&movie,0,0,0);
}

void Zombie_Pic::frameevent(int framenum){
    if(this->movie.frameCount()-1==framenum){
        this->hide();
        this->del=1;
    }
}

void Zombie_Pic::headevent(int framenum){
    if(this->headmovie.frameCount()-1==framenum){
        this->headmovie.stop();
        this->headlabel.hide();
        disconnect(&headmovie,0,0,0);
    }
}

void Zombie_Pic::Zombie_Froze(){
    froze=1;
    movie.stop();
    int now_frame=movie.currentFrameNumber();
    if(now_frame!=movie.frameCount()-1)now_frame++;
    else now_frame=0;
    if(attack){
        switch(type){
        case 0:
            movie.setFileName(":/image/res/ZombieAttack_Froze.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombieAttack_Froze.gif");
            break;
        case 2:
            movie.setFileName(":/image/res/BucketheadZombieAttack_Froze.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHeadAttack_Froze.gif");
            break;
        }
    }else{
        switch (type) {
        case 0:
            movie.setFileName(":/image/res/Zombie2_Froze.gif");
            break;
        case 1:
            movie.setFileName(":/image/res/ConeheadZombie_Froze.gif");
            break;
        case 2:
            movie.setFileName(":image/res/BucketheadZombie_Froze.gif");
            break;
        case 3:
            movie.setFileName(":/image/res/ZombieLostHead_Froze.gif");
            break;
        }
    }
    movie.jumpToFrame(now_frame);
    movie.start();
}

