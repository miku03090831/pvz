#include"sun_pic.h"

Sun_Pic::Sun_Pic(QWidget * parent, int x, int start_y, int end_y, int duration, int id){
    this->end_x=x;
    this->setParent(parent);
    int y;
    this->duration=duration;
    this->end_y=end_y;
    y=start_y;
    movie.setFileName(":/image/res/Sun.gif");
    this->setMovie(&movie);
    movie.start();
    this->move(x,y);
    this->show();
    this->id=id;
}

Sun_Pic::~Sun_Pic(){}

void Sun_Pic::sunmove(int speed){
    if(this->y()<end_y){
        this->move(this->x(),this->y()+speed);
    }
}


void Sun_Pic::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)emit clicked(id);
}
