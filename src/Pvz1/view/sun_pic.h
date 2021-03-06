﻿#ifndef SUN_PIC_H
#define SUN_PIC_H
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QMovie>
#include<QMouseEvent>

class Sun_Pic:public QLabel{
    Q_OBJECT
signals:
    void clicked(int);
public:
    Sun_Pic(QWidget* parent, int x,int start_y, int end_y, int duration, int id);   //阳光的初始化函数，分别为父窗口，横坐标，纵坐标开始位置，纵坐标结束位置，维持时间，其中x，y都是用像素，因为没有固定的位置,id反映为点击时信号参数
    ~Sun_Pic();
    void sunmove(int speed);    //向下移动speed个像素，如果已经大于结束位置则不移动
    int duration;   //持续时间的标尺，直接使用即可
    int id; //暂时还没有写响应函数，也许需要一个id写
    void mousePressEvent(QMouseEvent *event) override;
    void stopmovie();
private:
    int end_x;
    int end_y;
    QMovie movie;
};

#endif // SUN_PIC_H
