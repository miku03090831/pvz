#ifndef gamewindow2_H
#define gamewindow2_H

#include <QWidget>
#include "QPushButton"


class GameWindow2 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow2(QWidget *parent = 0);

    void sendslot();

private:
    QPushButton b4;


signals:
    void myslot();

public slots:


};

#endif // gamewindow2_H
