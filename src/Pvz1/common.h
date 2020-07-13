#ifndef COMMON_H
#define COMMON_H

#include <QLabel>
#include <QMovie>
#include <QMouseEvent>

//一个植物和僵尸都会继承的类
class Common : public QLabel{
    Q_OBJECT
public:
    explicit Common(QWidget* parent=0);
    bool alive=true;
    virtual void act()=0;//比如攻击，产阳光等
    int health=1;//生命值
};

#endif // COMMON_H
