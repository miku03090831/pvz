#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QLabel>

#include "../common/common.h"

class Zombie:public Common
{
    Q_OBJECT;
public:
    Zombie(QWidget* parent=0);
    virtual void act();
    virtual void hit(int damage);
    virtual void ice();
    int row=0;
    int offset=0;//攻击距离
    int interval=0;//攻击间隔
    bool iced=false;
    bool moving=true;
    double speed;
    double posX;//横坐标
};

class SimpleZombie:public Zombie
{
    Q_OBJECT
public:
    SimpleZombie(QWidget* parent=0);
    ~SimpleZombie();
    void act();
    void hit(int damage);
    void ice();
private:
    //关于僵尸的动画
};

class ConeheadZombie:public Zombie //路障僵尸
{
    Q_OBJECT;
public:
    ConeheadZombie(QWidget* parent=0);
    ~ConeheadZombie();
    void act();
    void hit(int damage);
    void ice();
private:
    int ConeHealth=200;
    bool HasCone=true;
};

class BucketZombie:public Zombie
{
    Q_OBJECT
public:
    BucketZombie(QWidget* parent=0);
    ~BucketZombie();
    void act();
    void hit(int damage);
    void ice();
private:
    int BucketHealth=400;
    bool HasBucket=true;
};

#endif // ZOMBIE_H
