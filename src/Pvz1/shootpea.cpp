#include "shootpea.h"

ShootPea::ShootPea()
{

}

void ShootPea::act()
{

}

Pea::Pea(QWidget* parent)
{
    //播放动画
    this->show();
    this->speed=10;
}

void Pea::act()
{
    this->raise();//相当于把豌豆放到最前面来，不被背景遮挡住
    this->move(this->x()+this->speed , this->y());
    //要加碰撞检测，是否碰到僵尸
    //遍历僵尸的vector,碰到后僵尸掉血，豌豆消失
}

Pea::~Pea()
{

}

Ice::Ice(QWidget* parent)
{
    //设置动画
    this->show();
    this->speed=10;
}

void Ice::act()
{
    this->raise();
    this->move(this->x()+this->speed,this->y());
    //同上，加和僵尸的碰撞检测
}

Ice::~Ice()
{

}


