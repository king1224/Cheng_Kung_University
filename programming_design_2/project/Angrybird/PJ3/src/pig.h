#ifndef PIG_H
#define PIG_H

#include <gameitem.h>
#include <iostream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 10.0f
#define PIG_FRICTION 0.2f
#define PIG_RESTITUTION 0.5f

class Pig : public GameItem
{
public:
    Pig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    int Kill();
private:
    int Hit=0;
    QGraphicsScene *Scene_Pig;
};

#endif // PIG_H
