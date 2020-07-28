#include"gameover_pic.h"

gameover_pic::gameover_pic(){
    eatbrain_pic.load(":/image/res/ZombiesWon.png");
    backtomenu.setStyleSheet("QPushButton{border-image:url(:/image/res/Backmenu.png);}");
    again.setStyleSheet("QPushButton{border-image:url(:/image/res/Again.png);}");
    eatbrain.setPixmap(eatbrain_pic);
    eatbrain.setParent(this);
    backtomenu.setParent(this);
    again.setParent(this);
    eatbrain.move(150,10);
    this->setGeometry(0,0,800,605);
    again.setGeometry(455,480,200,73);
    backtomenu.setGeometry(195,480,200,73);
    this->hide();
}
