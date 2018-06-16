#include "bullet.h"
#include "mainwindow.h"
#include <QDebug>

bullet::bullet()
{

}

void bullet::fly()
{
    setPos(x() + navig, y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::fly2()
{
    setPos(x(), y() + 1);
    if(y() > scene()->height()) {
        this->scene()->removeItem(this);
        delete this;
    }

}

void bullet::setNavig(double a){
    navig = a;
}

