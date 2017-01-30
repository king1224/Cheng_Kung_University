#ifndef WALL_GLASS_H
#define WALL_GLASS_H

#include <gameitem.h>
#include <wall.h>
#include <QGraphicsScene>

#define WALL_GLASS_DENSITY 100.0f
#define WALL_GLASS_FRICTION 0.05f
#define WALL_GLASS_RESTITUTION 0.35f

class Wall_Glass : public Wall
{
public:
    Wall_Glass(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int Kill();
private:
    int Hit=0;
    QGraphicsScene *Scene_Glass;
};

#endif // WALL_GLASS_H
