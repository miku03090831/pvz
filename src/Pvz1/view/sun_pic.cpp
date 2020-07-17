#include"sun_pic.h"

Sun_Pic::Sun_Pic(QWidget * parent, int x, int start_y, int end_y, int duration){
    this->end_x=x;
    this->setParent(parent);
    int y;
    this->duration=duration;
    this->end_y=end_y;
    y=start_y;
    sunbutton.setStyleSheet("QPushButton{background-color:transparent;}");
    movie.setFileName(":/image/res/Sun.gif");
    this->setMovie(&movie);
    movie.start();
    sunbutton.move(x,y);
    this->move(x,y);
    this->show();
}

Sun_Pic::~Sun_Pic(){}

void Sun_Pic::sunmove(int speed){
    if(this->y()<end_y){
        this->move(this->x(),this->y()+speed);
        sunbutton.move(this->x(),this->y());
    }
}
