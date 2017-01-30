#ifndef WALL_WOOD_H
#define WALL_WOOD_H

#include <gameitem.h>
#include <wall.h>
#include <QGraphicsScene>

#define WALL_WOOD_DENSITY 200.0f
#define WALL_WOOD_FRICTION 0.05f
#define WALL_WOOD_RESTITUTION 0.35f

class Wall_Wood : public Wall
{
public:
    Wall_Wood(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int Kill();
private:
    int Hit=0;
    QGraphicsScene *Scene_Wood;
};

#endif // WALL_WOOD_H
