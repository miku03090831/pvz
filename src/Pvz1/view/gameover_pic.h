#ifndef GAMEOVER_PIC_H
#define GAMEOVER_PIC_H
#include<QLabel>
#include<QPushButton>

class gameover_pic:public QLabel{
public:
    gameover_pic();
    QPushButton again;
    QPushButton backtomenu;

private:
    QPixmap eatbrain_pic;
    QLabel eatbrain;
};

#endif // GAMEOVER_PIC_H
