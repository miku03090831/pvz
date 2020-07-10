#ifndef gamewindow1_H
#define gamewindow1_H

#include <QWidget>
#include "QPushButton"


class GameWindow1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow1(QWidget *parent = 0);
    void sendslot();

private:
    QPushButton b3;

signals://自定义的一个信号，用于被发射（在sendsolt方法中被emit出去）
    void myslot();

public slots:

};

#endif // gamewindow1_H

