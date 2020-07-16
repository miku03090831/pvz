#ifndef SHOOTPEA_H
#define SHOOTPEA_H

#include <QWidget>
#include <QMovie>

#include "common.h"


class ShootPea:public Common
{
public:
    ShootPea(QWidget* parent=0);
    virtual void act();
    int row;//行数
};

class Pea:public ShootPea
{
public:
    Pea(QWidget* parent=0);
    ~Pea();
    void act();
private:
    //QMovie 飞行动画
    int speed;//飞行速度
};

class Ice:public ShootPea
{
public:
    Ice(QWidget* parent=0);
    ~Ice();
    void act();
private:
    //QMovie;
    int speed;//同上
};

#endif // SHOOTPEA_H
