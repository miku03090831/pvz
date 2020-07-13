#include "plant.h"

Plant::Plant(QWidget* parent):Common(parent)
{

}

void Plant::act()
{

}

void Plant::hit(int damage)
{
    this->health-=damage;
    if(this->health<=0)
        this->alive=false;
}

SinglePea::SinglePea(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=200;
    this->interval=50;
    this->timer=this->interval;
}

void SinglePea::act()
{
    if(this->timer<=0)
    {
        //if(没有敌人)
        //{
        //    return;
        //}
        this->timer=this->interval;
        //射出一个豌豆
        //关于豌豆的动画
    }
    else
        this->timer--;
}

SinglePea::~SinglePea()
{

}

IcePea::IcePea(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=200;
    this->interval=50;
    this->timer=this->interval;
}

void IcePea::act()
{
    if(this->timer<=0)
    {
//        if(没有敌人)
//        {
//            return;
//        }
        this->timer=this->interval;
        //射出一个豌豆
    }
    else
        this->timer--;
}

IcePea::~IcePea()
{

}

DoublePea::DoublePea(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=200;
    this->interval=50;
    this->timer=this->interval;
}

void DoublePea::act()
{
    if(this->timer<=0)
    {
//        if(没有敌人)
//        {
//            return;
//        }
        this->timer=this->interval;
        //射出一个豌豆
    }
    else if(this->timer==10)//为保证射出的两颗豌豆能够区分得开，需要让两颗豌豆保持一定的时间间隔
    {
//        if(没有敌人)
//        {
//            return;
//        }
        this->timer--;
        //射出一颗豌豆
    }
    else
        this->timer--;
}

DoublePea::~DoublePea()
{

}

SunFlower::SunFlower(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=200;
    this->interval=500;
    this->timer=this->interval;
}

void SunFlower::act()
{
    if(this->timer<=0)
    {
        this->timer=this->interval;
        //产生一个阳光
    }
    else
    {
        this->timer--;
    }
}

SunFlower::~SunFlower()
{

}

WallNut::WallNut(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=2000;
}

void WallNut::act()
{
    //根据血量多少，播放不同的动画，应该有三个阶段
    if(this->health < 1000 && this->health >=500)
    {
        //播放轻伤动画
    }
    else if(this->health < 500)
    {
        //播放重伤动画
    }
}

WallNut::~WallNut()
{

}

Cherry::Cherry(QWidget* parent):Plant(parent)
{
    //播放gif
    this->show();
    this->health=10000;
    this->timer=10;
}

void Cherry::act()
{
    if(this->timer<=0)
    {
        //搜索周围九个格子的僵尸，对他们全部造成大量伤害
        //并且播放爆炸动画
        this->alive=false;
    }
    else
        this->timer--;
}

Cherry::~Cherry()
{

}
