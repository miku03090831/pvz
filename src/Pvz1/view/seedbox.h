#ifndef SEEDBOX_H
#define SEEDBOX_H
#include<QLabel>
#include<QPushButton>
#include<QSignalMapper>

class Seedbox:public QLabel{
public:
    Seedbox();
    ~Seedbox();
    void SunNumChange(int sunnumber);   //设置阳光的数字
    QSignalMapper seedboxmapper;
    QPushButton p[6];
private:
    QPixmap seedbox_pic;

    QLabel suntext;
};

#endif // SEEDBOX_H
