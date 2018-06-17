#ifndef PLAYER_H
#define PLAYER_H


#include <QTimer>
#include <QDebug>
#include "Plane.h"
#include "bullet.h"


class Player : public Plane
{
    Q_OBJECT

public:
    Player();

public slots:
    void shoot();

    void test();

public:
//    QTimer *startingTimer;


#endif // PLAYER_H
