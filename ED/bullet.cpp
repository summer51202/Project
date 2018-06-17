#include "bullet.h"

Bullet::Bullet()
{

}

void Bullet::fly()
{

    setPos(x(), y() - 3);
    if(y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
