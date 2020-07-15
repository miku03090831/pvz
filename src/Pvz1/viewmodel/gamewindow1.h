#ifndef gamewindow1_H
#define gamewindow1_H

#include <QWidget>
#include "QPushButton"
#include<QMovie>
#include<QLabel>
#include<QLayout>
#include<QtGui>

#include "../common/common.h"
#include "../common/plant.h"
#include "../common/shootpea.h"
#include "../common/zombie.h"

class Plant_Pic:public QLabel{
    Q_OBJECT
public:
    Plant_Pic();
    int set_pic(int type);
    void removecherry();
    int gettype();
private:
    int type=0;
    QMovie movie;
public slots:
    void endstop(int framenumber);
};


class GameWindow1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow1(QWidget *parent = 0);
    void sendslot();
    void cursorchange(int cursortype);
    void plant_sunflower();//太阳花
    void plant_pea1();//豌豆射手
    void plant_pea2();//寒冰射手
    void plant_pea3();//双子射手
    void plant_cherry();//樱桃炸弹
    void plant_wallnut();//坚果墙
    void show_shovel();//铲子
    void mousePressEvent(QMouseEvent *event);
    static QList<Plant*> plants;//记录场上的植物
    static QList<ShootPea*> shootpeas;//记录场上飞行的豌豆
    static QList<Zombie*> zombies;
    static int ZombieNum[5];//记录场上每一行僵尸的数量

private:
    QPushButton b3,p0,p1,p2,p3,p4,p5,shovel,box[9][5];
    Plant_Pic pic[9][5];
    int cursor_type;
    QSignalMapper signalmapper;\




signals://自定义的一个信号，用于被发射（在sendsolt方法中被emit出去）
    void myslot();

public slots:
    void putplant(int place);
};


#endif // gamewindow1_H
