#include "zombie.h"
#include "../viewmodel/gamewindow1.h"

QList<Plant*> GameWindow1::plants;
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

}

SimpleZombie::~SimpleZombie()
{

}

void SimpleZombie::act()
{
    this->raise();//依旧是把僵尸显示在最顶层
    //遍历植物的qlist，看有没有吃的
    Plant* p;
    foreach(p,GameWindow1::plants)
    {
        if((qAbs(p->x() - this->x()) < 20) && (this->row == p->row) && (this->alive) )
        {
            if(this->interval <=0 )
            {
                this->interval=20;
                p->hit(100);
                //播放僵尸吃植物的动画
                this->moving=false;
            }
            this->interval--;
            return;
        }
    }
//    this->posX-=this->speed;
      this->moving=true;
//    this->move(this->posX,this->y());
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

ConeheadZombie::ConeheadZombie(QWidget* parent)
{
    this->speed=0.5;
    this->health=600;
    this->posX=805;

}

ConeheadZombie::~ConeheadZombie()
{

}


void ConeheadZombie::act()
{
    this->raise();//依旧是把僵尸显示在最顶层
    //遍历植物的qlist，看有没有吃的
    Plant* p;
    foreach(p,GameWindow1::plants)
    {
        if((qAbs(p->x() - this->x()) < 20) && (this->row == p->row) && (this->alive))
        {
            if(this->interval <=0 )
            {
                this->interval=20;
                p->hit(100);
                //播放僵尸吃植物的动画
                this->moving=false;
            }
            this->interval--;
            return;
        }
    }
//    this->posX-=this->speed;
      this->moving=true;
//    this->move(this->posX,this->y());
}

void ConeheadZombie::hit(int damage)
{
    if(damage>=2000)
    {
        this->alive=false;
        //播放被灰烬植物炸死的动画
        return;
    }
    if(this->HasCone)
    {
        this->ConeHealth-=damage;
        if(this->ConeHealth<=0)
        {
            this->HasCone=false;
            //然后将这个僵尸的动画换为普通僵尸的动画
        }
    }
    else
        this->health-=damage;
    if(this->health<=0)
        this->alive=false;
    //死亡动画
}

void ConeheadZombie::ice()
{
    if(this->iced)
        return;
    else
    {
        this->iced=true;
        this->speed/=2;
    }
}


BucketZombie::BucketZombie(QWidget* parent)
{
    this->speed=0.5;
    this->health=1200;
    this->posX=805;

}

BucketZombie::~BucketZombie()
{

}

void BucketZombie::act()
{
    this->raise();//依旧是把僵尸显示在最顶层
    //遍历植物的qlist，看有没有吃的
    Plant* p;
    foreach(p,GameWindow1::plants)
    {
        if((qAbs(p->x() - this->x()) < 20) && (this->row == p->row) && (this->alive))
        {
            if(this->interval <=0 )
            {
                this->interval=20;
                p->hit(100);
                //播放僵尸吃植物的动画
                this->moving=false;
            }
            this->interval--;
            return;
        }
    }
      this->moving=true;
//    this->posX-=this->speed;
//    this->move(this->posX,this->y());
}

void BucketZombie::hit(int damage)
{
    if(damage>=2000)
    {
        this->alive=false;
        //播放被灰烬植物炸死的动画
        return;
    }
    if(this->HasBucket)
    {
        this->BucketHealth-=damage;
        if(this->BucketHealth<=0)
        {
            this->HasBucket=false;
            //然后将这个僵尸的动画换为普通僵尸的动画
        }
    }
    else
        this->health-=damage;
    if(this->health<=0)
        this->alive=false;
    //死亡动画
}

void BucketZombie::ice()
{
    if(this->iced)
        return;
    else
    {
        this->iced=true;
        this->speed/=2;
    }
}
