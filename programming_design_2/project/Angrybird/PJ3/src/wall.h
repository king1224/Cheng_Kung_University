#ifndef WALL_H
#define WALL_H

#include <gameitem.h>
#include <iostream>

class Wall : public GameItem
{
public:
    Wall(b2World *world);
    void Set_Transform(float angel);
    virtual int Kill();
private:
    int Hit=0;
};

#endif // WALL_H
