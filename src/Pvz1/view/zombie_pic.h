#ifndef ZOMBIE_PIC_H
#define ZOMBIE_PIC_H
#include<QLabel>
#include<QWidget>
#include<QMovie>

class Zombie_Pic:QLabel{
    Q_OBJECT;
public:
    Zombie_Pic(QWidget *parent, int y, int type, int interval, int movetime);
    //四个参数，分别为父窗口，用this就行，y出生的行0-4，type 0-2，分别为普通僵尸，路障，铁桶
    //interval是每次前移间隔的时间，movetime是每次走动持续的时间，例如我设置interval=7，movetime=3
    //则每10次调用move函数，前七次不进行走动，后三次每次走动speed的像素长度
    ~Zombie_Pic();
    void Zombie_Move(int speed);        //僵尸移动
    void Zombie_Change();   //路障/铁桶僵尸变为普通僵尸
    void Zombie_Attack();   //改变为攻击状态
    void Zombie_Die();  //死亡，死亡时僵尸应该处于LostHead状态
    void Zombie_Walk();     //将僵尸调整为走动状态，只改变图像
    void Zombie_LostHead(); //僵尸头掉了，保持原来的动画状态（行走/攻击）
    void Zombie_Froze();    //等着之后写
    void Zombie_Burn(); //被烧死，之后会添加消除图像的函数
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
