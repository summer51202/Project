#include "enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(QObject *parent)
{
    eMapper = new QSignalMapper(parent);
    eTimer = new QTimer;
    mTimer = new QTimer;
    eTimer->start(1);
    mTimer->start(10);

    GPixmap.setPixmap(QPixmap("../ED/enemy.png").scaled(120, 100));
    GPixmap.setPos((qrand() % 9)*100, 0);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(move()));
    connect(eTimer, SIGNAL(timeout()), eMapper, SLOT(map()));
    eMapper->setMapping(eTimer, this);
}

Enemy::~Enemy(){
    eMapper->removeMappings(eTimer);
}

void Enemy::move()
{
    GPixmap.setPos(GPixmap.x(), GPixmap.y() + 1);
    if(GPixmap.y() > GPixmap.scene()->height()) {
        GPixmap.scene()->removeItem(&GPixmap);
        delete this;
    }
}
