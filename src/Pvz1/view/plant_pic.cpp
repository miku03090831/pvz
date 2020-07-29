#include"plant_pic.h"

Plant_Pic::Plant_Pic(){
    this->hide();
    this->setMovie(&movie);
    connect(&movie,SIGNAL(frameChanged(int)),this,SLOT(framechange(int)));
}

void Plant_Pic::framechange(int framenumber){
    if(framenum==this->movie.frameCount()-1&&type==5){
        set_pic(0);
        this->move(this->x()+20,this->y()+10);
        return;
    }else{
        this->framenum=framenumber;
    }
}

int Plant_Pic::set_pic(int type){   //显示植物，0为不显示，之后依次按照植物栏每种植物
    switch (type) {
    case 0:
        movie.stop();
        this->hide();
        this->type=0;
        return 0;
    case 1:
        movie.setFileName(":/image/res/Sunflower.gif"); //太阳花
        movie.start();
        this->type=1;
        this->show();
        return 0;
    case 2:
        movie.setFileName(":/image/res/Peashooter.gif");    //豌豆
        movie.start();
        this->type=2;
        this->show();
        return 0;
    case 3:
        movie.setFileName(":/image/res/SnowPea.gif");   //寒冰
        movie.start();
        this->type=3;
        this->show();
        return 0;
    case 4:
        movie.setFileName(":/image/res/Repeater.gif");  //双发
        movie.start();
        this->type=4;
        this->show();
        return 0;
    case 5:
        movie.setFileName(":/image/res/CherryBomb2.gif");   //炸弹
        movie.start();
        this->move(this->x()-20,this->y()-10);
        this->type=5;
        this->show();
        return 0;
    case 6:
        movie.setFileName(":/image/res/WallNut.gif");   //坚果墙
        movie.start();
        this->type=6;
        this->show();
        return 0;
    case 7:
        movie.setFileName(":/image/res/Wallnut_cracked1.gif");  //损毁坚果墙
        movie.start();
        this->type=7;
        this->show();
        return 0;
    case 8:
        movie.setFileName(":/image/res/Wallnut_cracked2.gif");  //损毁坚果墙2
        movie.start();
        this->type=8;
        this->show();
        return 0;
    }
}

void Plant_Pic::removecherry(){ //手动去除樱桃一定调用这个，不能直接set_pic
    set_pic(0);
    this->move(this->x()+20,this->y()+10);
    return;
}

int Plant_Pic::gettype(){
    return type;
}

Plant_Pic::~Plant_Pic(){}

int Plant_Pic::getx(){
    return this->x();
}

int Plant_Pic::gety(){
    return this->y();
}

void Plant_Pic::stopmovie(){
    movie.stop();
}
