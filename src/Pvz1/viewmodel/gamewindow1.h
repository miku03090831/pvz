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
#include "../model/plant.h"
#include "../model/shootpea.h"
#include "../model/zombie.h"
#include"../view/plant_pic.h"
#include"../view/zombie_pic.h"
#include"../view/pea_pic.h"
#include"../view/seedbox.h"
#include"../view/sun_pic.h"
#include"../view/gameover_pic.h"

class GameWindow1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow1(QWidget *parent = 0);
    void sendslot();
    void cursorchange(int cursortype);
    void plant1();
    void sunlight_sub();
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
    static QList<Pea_Pic*> p_pic;
    static int ZombieNum[5];//记录场上每一行僵尸的数量
    void append_plant(int col, int row);
    void delete_plant(int col, int row);
    void gameover();    //游戏结束

private:
    QPushButton b3,shovel,box[9][5];
    Plant_Pic pic[9][5];
    int cursor_type;
    int Sunlight_num=50;
    int zombie_G_mode=3;
    int zombie_G_speed=3;//G_mode是产生僵尸类型的限制，G_speed是产生僵尸的速度限制
    QSignalMapper signalmapper;
    QLabel plantbox;
    Seedbox seedbox;
    QPixmap plantbox_pic;
    gameover_pic gaover_pic;
    QTimer sun_timer1,sun_timer2,alive_check,plant_act,zombieMove_timer1,zombieGen_timer1;



signals://自定义的一个信号，用于被发射（在sendsolt方法中被emit出去）
    void myslot();
    void again();
    void backtomenu();

public slots:
    void putplant(int place);
    void seedbox_clicked(int planttype);
    void move_zombie();
    void generate_zombie();//僵尸生成函数
    void win1again();
    void win1backtomenu();
    void sun_move();
    void sun_down();
    void zombie_hide();
    void plant_death();
    void sun_click(int);
    void set_sun_num();
    void act_plant();
    void move_pea();
    void act_pea();
    void pea_hide();
};



#endif // gamewindow1_H
