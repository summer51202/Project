#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class plane : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    plane();

public slots:
    void shoot();
    void setLives(int l);
    int getLives();
private:
    int lives;
};

#endif // PLANE_H
