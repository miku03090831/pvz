#ifndef ZOMBIE_PIC_H
#define ZOMBIE_PIC_H
#include<QLabel>
#include<QWidget>
#include<QMovie>

class Zombie_Pic:QLabel{
    Q_OBJECT;
public:
    Zombie_Pic(QWidget *parent, int y, int type, int interval, int movetime);
    ~Zombie_Pic();
    void Zombie_Move(int speed);
    void Zombie_Change();
    void Zombie_Attack();
    void Zombie_Die();
    void Zombie_Walk();
    void Zombie_LostHead();
    void Zombie_Froze();
    void Zombie_Burn();
private:
    QMovie movie;
    QLabel headlabel;
    QMovie headmovie;
    int frame;
    int time;
    int type;
    int attack;
    int interval;
    int losthead;
    int movetime;
};

#endif // ZOMBIE_PIC_H
