#ifndef ENEMY_H
#define ENEMY_H

#include <QSignalMapper>
#include <QTimer>
#include "plane.h"

class Enemy : public Plane
{
    Q_OBJECT
public:
    Enemy(QObject *parent);
    Enemy();
    ~Enemy();
public slots:
    void move();
public:
    QSignalMapper *eMapper;
    QTimer *eTimer;
    QTimer *mTimer;
};

#endif // ENEMY_H
