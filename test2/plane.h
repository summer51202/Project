#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Plane : public QObject
{
    friend class MainWindow;
    Q_OBJECT
public:
    Plane();

public slots:
    void shoot();

public:
    int lives;
    QGraphicsPixmapItem GPixmap;
};

#endif // PLANE_H
