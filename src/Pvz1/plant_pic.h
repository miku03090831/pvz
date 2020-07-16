#ifndef PLANT_PIC_H
#define PLANT_PIC_H

#include<QLabel>
#include<QMovie>


class Plant_Pic:public QLabel{
    Q_OBJECT
public:
    Plant_Pic();
    int set_pic(int type);
    void removecherry();
    ~Plant_Pic();
    int gettype();
private:
    int type=0;
    int framenum;
    QMovie movie;
public slots:
    void framechange(int framenumber);
};

#endif // PLANT_PIC_H
