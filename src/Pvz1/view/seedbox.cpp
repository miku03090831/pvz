#include"../view/seedbox.h"

Seedbox::Seedbox(){
    this->move(0,0);
    seedbox_pic.load(":/image/res/seedbox.png");
    this->setPixmap(seedbox_pic);
    int i;
    for(i=0;i<6;i++){
        p[i].setParent(this);
        p[i].setGeometry(88+60*i,5,50,75);
        connect(&p[i],SIGNAL(clicked()),&seedboxmapper,SLOT(map()));
        seedboxmapper.setMapping(&p[i],i+1);
    }

    QFont ft;   //设置阳光数字
    ft.setPointSize(12);
    suntext.setFont(ft);
    suntext.setAlignment(Qt::AlignCenter);
    suntext.setGeometry(19,61,40,20);
    suntext.setParent(this);
    suntext.setNum(50);
    suntext.show();

    p[0].setStyleSheet("QPushButton{border-image:url(:/image/res/sun_flower.png);}");
    p[1].setStyleSheet("QPushButton{border-image:url(:/image/res/peanut_box.png);}");
    p[2].setStyleSheet("QPushButton{border-image:url(:/image/res/snowpeanut_box.png);}");
    p[3].setStyleSheet("QPushButton{border-image:url(:/image/res/repeater_box.png);}");
    p[4].setStyleSheet("QPushButton{border-image:url(:/image/res/cherry_box.png);}");
    p[5].setStyleSheet("QPushButton{border-image:url(:/image/res/wallnut_box.png);}");
}

Seedbox::~Seedbox(){}

void Seedbox::SunNumChange(int sunnumber){
    suntext.setNum(sunnumber);
}
