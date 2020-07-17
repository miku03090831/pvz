#include "../viewmodel/gamewindow1.h"
#include"pea_pic.h"

Pea_Pic::Pea_Pic(GameWindow1 *parent, int x, int y, int speed){ //分别为父窗口，用this就行，xy为起始的列行，分别为0-8，0-4，speed为每次移动的距离
    this->setParent(parent);
    this->move(115+81*x,100+98*y);
    this->speed=speed;
<<<<<<< HEAD
    this->del=0;
=======
>>>>>>> 8368bf716d1edf349ad04e95cc3416196e5914d0
}

void Pea_Pic::Pea_Move(){   //豌豆向前飞
    this->move(this->x()+speed,this->y());
    const QPixmap *p;
    p=this->pixmap();
    return ;
}

void Snow_Pea::Pea_Hit(){   //击中的图像
    this->raise();
<<<<<<< HEAD
    this->del=1;
=======
>>>>>>> 8368bf716d1edf349ad04e95cc3416196e5914d0
    this->setPixmap(((GameWindow1*)(this->parent()))->peahit);
    this->show();
    return ;
}

void Normal_Pea::Pea_Hit(){ //击中的图像
    this->raise();
    this->setPixmap(((GameWindow1*)(this->parent()))->peahit);
<<<<<<< HEAD
    this->del=1;
=======
>>>>>>> 8368bf716d1edf349ad04e95cc3416196e5914d0
    this->show();
    return ;
}

Pea_Pic::~Pea_Pic(){}

Snow_Pea::Snow_Pea(GameWindow1 *parent, int x, int y, int speed):Pea_Pic(parent,x,y,speed){ //注释同Pea_Pic
    this->raise();
    this->setPixmap(parent->snowpea);
    this->show();
    return ;
}

Snow_Pea::~Snow_Pea(){}
Normal_Pea::Normal_Pea(GameWindow1 *parent, int x, int y, int speed):Pea_Pic(parent,x,y,speed){//注释同Pea_Pic
    this->raise();
    this->setPixmap(parent->normalpea);
    this->show();
    return ;
}

Normal_Pea::~Normal_Pea(){}
