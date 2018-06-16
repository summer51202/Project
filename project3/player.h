#ifndef PLAYER_H
#define PLAYER_H

#include "plane.h"

class player : public plane
{
    Q_OBJECT
public:
    player();

public slots:
    void shoot();
};

#endif // PLAYER_H
