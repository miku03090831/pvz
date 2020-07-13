#include "zombie.h"

Zombie::Zombie(QWidget* parent):Common(parent)
{

}

void Zombie::act()
{

}

void Zombie::hit(int damage)
{

}

void Zombie::ice()
{

}

SimpleZombie::SimpleZombie(QWidget* parent)
{
    //设置出场动画
    //设置攻击动画(都是先只设置，不播放）

    this->speed=0.5;
    this->health=200;
    this->posX=805;
    this->show();
}

SimpleZombie::~SimpleZombie()
{

}

void SimpleZombie::act()
{
    this->raise();//依旧是把僵尸显示在最顶层
    //遍历植物的qlist，看有没有吃的
    this->posX-=this->speed;
    this->move(this->posX,this->y());
}

void SimpleZombie::hit(int damage)
{
    if(damage >= 200)//被灰烬植物炸死，和普通死亡不同
    {
        this->alive=false;
        //播放被炸死的动画
        return;
    }
    this->health-=damage;
    if(this->health <= 0)
    {
        this->alive=false;
        //播放普通死亡动画
    }
}

void SimpleZombie::ice()
{
    if(this->iced)
        return;
    else
    {
        this->iced=true;
        this->speed/=2;
    }
}
