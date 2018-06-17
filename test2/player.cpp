#include "Player.h"
#include "iostream"
Player::Player()
{

}

void Player::shoot(){
    using namespace std;
    cout << "b";

}

void Player::collisionAnimation(QPointF pos){
    x = pos.x();
    y = pos.y();
    boom = new QGraphicsPixmapItem;
    boomTimer = new QTimer;
    connect(boomTimer, SIGNAL(timeout()), this, SLOT(booming()));
    boomState = 0;
    boom->setPixmap(QPixmap("../test2/boom.png").scaled(50, 50));
    boom->setPos(x+ GPixmap.pixmap().width()/2, y+ GPixmap.pixmap().height()/2);
    GPixmap.scene()->addItem(boom);
    qDebug() << "gggggg";
}

void Player::test(){
    qDebug() << "test";
}
void Player::booming(){
    ++boomState;
    qDebug() << "ssssssssssssss";
    qDebug() << boomState;
    boom->setScale(GPixmap.scale()/10 * boomState);
    boom->setPos(x + GPixmap.pixmap().width()/2 * (10 - boomState)/10, y + GPixmap.pixmap().height()/2 * (10 - boomState)/10);
    if(boomState == 10){
        boomTimer->stop();

    }
}
