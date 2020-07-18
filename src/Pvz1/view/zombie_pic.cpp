#include"zombie_pic.h"

Zombie_Pic::Zombie_Pic(QWidget* parent, int y, int type, int interval, int movetime){   //四个参数，分别为父窗口，用this就行，y出生的行0-4，type 0-2，分别为普通僵尸，路障，铁桶
    this->setParent(parent);                                                            //interval是每次前移间隔的时间，movetime是每次走动持续的时间，例如我设置interval=7，movetime=3
    headlabel.setParent(parent);                                                        //则每10次调用move函数，前七次不进行走动，后三次每次走动speed的像素长度
    this->resize(102,144);
    switch (type) {
    case 0:
        movie.setFileName(":/image/res/Zombie.gif");
        this->type=0;
        break;
    case 1:
        movie.setFileName(":/image/res/ConeheadZombie.gif");
        this->type=1;
        break;
    case 2:
        movie.setFileName(":image/res/BucketheadZombie.gif");
        this->type=2;
        break;
    }
    this->interval=interval;
    headmovie.setFileName(":image/res/ZombieHead.gif");
    headlabel.setMovie(&headmovie);
    this->setMovie(&movie);
    this->time=0;
    headlabel.hide();
    movie.start();
    this->movetime=movetime;
    this->move(500,20+98*y);
    this->dead=0;
    this->del=0;
    connect(&movie,SIGNAL(frameChanged()),this,SLOT(frameevent()));
    this->show();
}

void Zombie_Pic::Zombie_Walk(){ //将僵尸调整为走动状态，只改变图像
    this->attack=0;
    movie.stop();
    switch (type) {
    case 0:
        movie.setFileName(":/image/res/Zombie.gif");
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
    movie.start();
    this->show();
}

void Zombie_Pic::Zombie_Die(){  //死亡，死亡时僵尸应该处于LostHead状态
    movie.stop();
    this->dead=1;
    movie.setFileName(":/image/res/ZombieDie.gif");
    movie.start();
}

void Zombie_Pic::Zombie_Change(){   //路障/铁桶僵尸变为普通僵尸
    movie.stop();
    if(type==1)movie.setFileName(":/image/res/Zombie.gif");
    else movie.setFileName(":image/res/Zombie2.gif");
    this->type=0;
    movie.start();
}

void Zombie_Pic::Zombie_LostHead(){ //僵尸头掉了，保持原来的动画状态（行走/攻击）
    movie.stop();
    headlabel.move(this->x()+65,this->y());
    this->type=3;
    switch (attack) {
    case 0:
         movie.setFileName(":image/res/ZombieLostHead.gif");
         break;
    case 1:
        movie.setFileName(":image/res/ZombieLostHeadAttack.gif");
        break;
    }
    movie.start();
    headmovie.start();
    connect(&headmovie,SIGNAL(frameChanged()),this,SLOT(headevent()));
    this->show();
    headlabel.show();
}

void Zombie_Pic::Zombie_Burn(){ //被烧死，之后会添加消除图像的函数
    movie.stop();
    this->dead=1;
    movie.setFileName(":/image/res/BurnDie.gif");
    movie.start();
}

Zombie_Pic::~Zombie_Pic(){}

void Zombie_Pic::frameevent(int framenum){
    if(this->dead&&this->movie.frameCount()-1==framenum){
        this->hide();
        this->del=1;
    }else this->frame=framenum;
}

void Zombie_Pic::headevent(int framenum){
    if(this->headmovie.frameCount()-1==framenum){
        this->headmovie.stop();
        this->headlabel.hide();
        disconnect(&headmovie,0,0,0);
    }
}
