#ifndef BULLET_H
#define BULLET_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "plane.h"

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();

public slots:
    void fly();

private:

};

#endif // BULLET_H
