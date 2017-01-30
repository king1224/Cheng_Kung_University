#ifndef WALL_FAKE_H
#define WALL_FAKE_H

#include <gameitem.h>
#include <wall.h>
#include <QGraphicsScene>

class Wall_Fake : public Wall
{
public:
    Wall_Fake(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void Set_Transform(float pos_x);
};

#endif // WALL_FAKE_H
