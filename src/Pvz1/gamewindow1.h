#ifndef gamewindow1_H
#define gamewindow1_H

#include <QWidget>
#include "QPushButton"
#include<QMovie>
#include<QLabel>
#include<QLayout>
#include<QtGui>

#include "common.h"
#include "plant.h"
#include "shootpea.h"

class Plant_Pic:public QLabel{
    Q_OBJECT
public:
    Plant_Pic();
    int set_pic(int type);
    void removecherry();
    int gettype();
private:
    int type=0;
    QMovie movie;
public slots:
    void endstop(int framenumber);
};


class GameWindow1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow1(QWidget *parent = 0);
    void sendslot();
    void cursorchange(int cursortype);
    void plant1();
    void mousePressEvent(QMouseEvent *event);
    static QList<Plant*> plants;//记录场上的植物
    static QList<ShootPea*> shootpeas;//记录场上飞行的豌豆

private:
    QPushButton b3,p0,p1,p2,p3,p4,p5,shovel,box[9][5];
    Plant_Pic pic[9][5];
    int cursor_type;
    QSignalMapper signalmapper;\




signals://自定义的一个信号，用于被发射（在sendsolt方法中被emit出去）
    void myslot();

public slots:
    void putplant(int place);
};


#endif // gamewindow1_H
