#ifndef PLANT_PIC_H
#define PLANT_PIC_H

#include<QLabel>
#include<QMovie>


class Plant_Pic:public QLabel{  //基本没有改变
    Q_OBJECT
public:
    Plant_Pic();
    int set_pic(int type);
    void removecherry();
    ~Plant_Pic();
    int gettype();
    int getx();
    int gety();
    void stopmovie();
private:
    int type=0;
    int framenum;
    QMovie movie;
public slots:
    void framechange(int framenumber);  //对于樱桃炸弹的判断进行了更改，现在每个植物都有一个与帧相关的函数，与未来的优化有关
};

#endif // PLANT_PIC_H
