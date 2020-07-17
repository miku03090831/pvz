#ifndef PEA_PIC_H
#define PEA_PIC_H
#include<QLabel>
class GameWindow1;
class Pea_Pic:public QLabel{
public:
    Pea_Pic(GameWindow1* parent,int x, int y, int speed);   //分别为父窗口，用this就行，xy为起始的列行，分别为0-8，0-4，speed为每次移动的距离
    void Pea_Move();    //豌豆向前飞
    ~Pea_Pic();
    int del; //=1表示应该删除
private:
    int speed;
};


class Normal_Pea:public Pea_Pic{
public:
    Normal_Pea(GameWindow1* parent,int x, int y, int speed);
    ~Normal_Pea();
    void Pea_Hit(); //击中的图像
};

class Snow_Pea:public Pea_Pic{
public:
    Snow_Pea(GameWindow1* parent,int x, int y, int speed);
    ~Snow_Pea();
    void Pea_Hit(); //击中的图像
};

#endif // PEA_PIC_H
