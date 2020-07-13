#ifndef PLANT_H
#define PLANT_H

#include <QLabel>
#include <QMovie>
#include <QMouseEvent>

#include "common.h"

//植物基类
class Plant:public Common
{
    Q_OBJECT
public:
    Plant(QWidget* parent=0);
    virtual void act();//这个包括攻击，产阳光等
    virtual void hit(int damage);//这个是被攻击
    int x,y;
};

//豌豆射手
class SinglePea:public Plant
{
    Q_OBJECT
public:
    SinglePea(QWidget* parent=0);
    ~SinglePea();
    void act();
private:
    //Qmovie 加载一个gif图
    int timer,interval;//与攻击速度相关,interval是两次攻击的间隔，然后timer就是一个计时器，每当timer等于interval的时候就攻击一次，并且把timer清零
};

//寒冰射手
class IcePea:public Plant
{
    Q_OBJECT
public:
    IcePea(QWidget* parent=0);
    ~IcePea();
    void act();
private:
    //Qmovie
    int timer,interval;
};

//双发射手
class DoublePea:public Plant
{
    Q_OBJECT
public:
    DoublePea(QWidget* parent=0);
    ~DoublePea();
    void act();
private:
    //Qmovie
    int timer,interval;
};

//坚果墙
class WallNut:public Plant
{
    Q_OBJECT;
public:
    WallNut(QWidget* parent=0);
    ~WallNut();
    void act();
private:
    //QMovie
};

//向日葵
class SunFlower:public Plant
{
    Q_OBJECT
public:
    SunFlower(QWidget* parent=0);
    ~SunFlower();
    void act();
private:
    //QMovie
    int timer,interval;
};

//樱桃炸弹
class Cherry:public Plant
{
    Q_OBJECT
public:
    Cherry(QWidget* parent=0);
    ~Cherry();
    void act();
private:
    //QMovie
    int timer;
};

#endif // PLANT_H
