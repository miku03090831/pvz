#include"gamewindow1.h"
#include"pea_pic.h"

Pea_Pic::Pea_Pic(GameWindow1 *parent, int x, int y, int speed){
    this->setParent(parent);
    this->move(115+81*x,100+98*y);
    this->speed=speed;
}

void Pea_Pic::Pea_Move(){
    this->move(this->x()+speed,this->y());
    const QPixmap *p;
    p=this->pixmap();
    return ;
}

void Snow_Pea::Pea_Hit(){
    this->raise();
    this->setPixmap(((GameWindow1*)(this->parent()))->peahit);
    this->show();
    return ;
}

void Normal_Pea::Pea_Hit(){
    this->raise();
    this->setPixmap(((GameWindow1*)(this->parent()))->peahit);
    this->show();
    return ;
}

Pea_Pic::~Pea_Pic(){}

Snow_Pea::Snow_Pea(GameWindow1 *parent, int x, int y, int speed):Pea_Pic(parent,x,y,speed){
    this->raise();
    this->setPixmap(parent->snowpea);
    this->show();
    return ;
}

Snow_Pea::~Snow_Pea(){}
Normal_Pea::Normal_Pea(GameWindow1 *parent, int x, int y, int speed):Pea_Pic(parent,x,y,speed){
    this->raise();
    this->setPixmap(parent->normalpea);
    this->show();
    return ;
}

Normal_Pea::~Normal_Pea(){}
