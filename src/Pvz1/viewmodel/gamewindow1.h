#ifndef gamewindow1_H
#define gamewindow1_H

#include <QWidget>
#include "QPushButton"
#include<QMovie>
#include<QLabel>
#include<QLayout>
#include<QtGui>
#include<QtGlobal>

#include "../common/common.h"
#include "../common/plant.h"
#include "../common/shootpea.h"
#include "../common/zombie.h"
#include"../view/plant_pic.h"
#include"../view/zombie_pic.h"
#include"../view/pea_pic.h"
#include"../view/seedbox.h"
#include"../view/sun_pic.h"

class GameWindow1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow1(QWidget *parent = 0);
    void sendslot();
    void cursorchange(int cursortype);
    void plant1();
    void starttimer();
    int Gen_Rand(int upper);
    Sun_Pic *sp;
    void show_shovel();//铲子
    void mousePressEvent(QMouseEvent *event);
    QPixmap normalpea, snowpea, peahit; //两种豆子的图像及击中图像
    static QList<Plant*> plants;//记录场上的植物
    static QList<ShootPea*> shootpeas;//记录场上飞行的豌豆
    static QList<Zombie*> zombies;
    static QList<Zombie_Pic*> z_pic;
    static QList<Sun_Pic*> sunlight;
    static int ZombieNum[5];//记录场上每一行僵尸的数量

private:
    QPushButton b3,shovel,box[9][5];
    Plant_Pic pic[9][5];
    int cursor_type;
    int zombie_G_mode=3;
    int zombie_G_speed=3;//G_mode是产生僵尸类型的限制，G_speed是产生僵尸的速度限制
    QSignalMapper signalmapper;
    QTimeLine timer;
    QLabel plantbox;
    Seedbox seedbox;
    QPixmap plantbox_pic;



signals://自定义的一个信号，用于被发射（在sendsolt方法中被emit出去）
    void myslot();

public slots:
    void putplant(int place);
    void seedbox_clicked(int planttype);
    void move_zombie();
    void generate_zombie();//僵尸生成函数
    void sun_move();
    void sun_down();
};



#endif // gamewindow1_H
