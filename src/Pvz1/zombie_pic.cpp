#include<zombie_pic.h>

Zombie_Pic::Zombie_Pic(QWidget* parent, int y, int type, int interval, int movetime){
    this->setParent(parent);
    headlabel.setParent(parent);
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
    this->show();
}

void Zombie_Pic::Zombie_Walk(){
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

void Zombie_Pic::Zombie_Move(int speed){
    if(time>=interval){
        this->move(this->x()-speed,this->y());
    }
    time++;
    if(time==interval+movetime){
        time=0;
    }
}

void Zombie_Pic::Zombie_Attack(){
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

void Zombie_Pic::Zombie_Die(){
    movie.stop();
    movie.setFileName(":/image/res/ZombieDie.gif");
    movie.start();
}

void Zombie_Pic::Zombie_Change(){
    movie.stop();
    if(type==1)movie.setFileName(":/image/res/Zombie.gif");
    else movie.setFileName(":image/res/Zombie2.gif");
    this->type=0;
    movie.start();
}

void Zombie_Pic::Zombie_LostHead(){
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
    this->show();
    headlabel.show();
}

void Zombie_Pic::Zombie_Burn(){
    movie.stop();
    movie.setFileName(":/image/res/BurnDie.gif");
    movie.start();
}

Zombie_Pic::~Zombie_Pic(){}
