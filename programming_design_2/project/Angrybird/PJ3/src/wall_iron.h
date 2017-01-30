#ifndef WALL_IRON_H
#define WALL_IRON_H

#include <gameitem.h>
#include <wall.h>
#include <QGraphicsScene>

#define WALL_IRON_DENSITY 300.0f
#define WALL_IRON_FRICTION 100.0f
#define WALL_IRON_RESTITUTION 0.35f

class Wall_Iron : public Wall
{
public:
    Wall_Iron(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int Kill();
private:
    int Hit=0;
    QGraphicsScene *Scene_Iron;
};

#endif // WALL_IRON_H
