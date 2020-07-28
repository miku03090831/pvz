#include "shootpea.h"
#include "../viewmodel/gamewindow1.h"
//QList<Zombie*> GameWindow1::zombies;

ShootPea::ShootPea(QWidget* parent): Common(parent)
{

}

void ShootPea::act()
{

}

Pea::Pea(QWidget* parent) : ShootPea(parent)
{
    //播放动画
    this->speed=10;
}

void Pea::act()
{
    this->raise();//相当于把豌豆放到最前面来，不被背景遮挡住
    this->move(this->x()+this->speed , this->y());
    //要加碰撞检测，是否碰到僵尸
    //遍历僵尸的vector,碰到后僵尸掉血，豌豆消失
    Zombie* z;
    foreach(z,GameWindow1::zombies)
    {
        if((qAbs(z->x() - this->x() < 0))&&(this->row == z->row) && (this->alive))
        {
            this->alive=false;
            z->hit(10);
            return;
        }
    }
}

Pea::~Pea()
{

}

Ice::Ice(QWidget* parent)
{
    //设置动画
    this->speed=10;
}

void Ice::act()
{
    this->raise();
    this->move(this->x()+this->speed,this->y());
    //同上，加和僵尸的碰撞检测
    Zombie* z;
    foreach(z,GameWindow1::zombies)
    {
        if((qAbs(z->x() - this->x() < 0))&&(this->row == z->row) && (this->alive))
        {
            this->alive=false;
            z->hit(10);
            z->ice();
            return;
        }
    }

}

Ice::~Ice()
{

}


