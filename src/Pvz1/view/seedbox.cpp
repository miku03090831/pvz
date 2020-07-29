#include"../view/seedbox.h"

Seedbox::Seedbox(){
    this->move(0,0);
    seedbox_pic.load(":/image/res/seedbox.png");
    box_pic[0].load(":/image/res/sun_flower.png");
    box_pic[1].load(":/image/res/peanut_box.png");
    box_pic[2].load(":/image/res/snowpeanut_box.png");
    box_pic[3].load(":/image/res/repeater_box.png");
    box_pic[4].load(":/image/res/cherry_box.png");
    box_pic[5].load(":/image/res/wallnut_box.png");
    this->setPixmap(seedbox_pic);
    int i;
    for(i=0;i<6;i++){
        p[i].setParent(this);
        p[i].setGeometry(88+60*i,5,50,75);
        p[i].setPixmap(box_pic[i]);
    }

    QFont ft;   //设置阳光数字
    ft.setPointSize(12);
    suntext.setFont(ft);
    suntext.setAlignment(Qt::AlignCenter);
    suntext.setGeometry(19,61,40,20);
    suntext.setParent(this);
    suntext.setNum(50);
    suntext.show();


}

Seedbox::~Seedbox(){}

void Seedbox::SunNumChange(int sunnumber){
    suntext.setNum(sunnumber);
}
