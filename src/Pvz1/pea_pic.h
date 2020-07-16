#ifndef PEA_PIC_H
#define PEA_PIC_H
#include<QLabel>
class GameWindow1;
class Pea_Pic:public QLabel{
public:
    Pea_Pic(GameWindow1* parent,int x, int y, int speed);
    void Pea_Move();
    ~Pea_Pic();
private:
    int speed;
};


class Normal_Pea:public Pea_Pic{
public:
    Normal_Pea(GameWindow1* parent,int x, int y, int speed);
    ~Normal_Pea();
    void Pea_Hit();
};

class Snow_Pea:public Pea_Pic{
public:
    Snow_Pea(GameWindow1* parent,int x, int y, int speed);
    ~Snow_Pea();
    void Pea_Hit();
};

#endif // PEA_PIC_H
