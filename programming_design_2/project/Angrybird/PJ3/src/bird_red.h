#ifndef BIRD_RED_H
#define BIRD_RED_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_RED_DENSITY 50.0f
#define BIRD_RED_FRICTION 0.2f
#define BIRD_RED_RESTITUTION 0.5f

class Bird_Red : public Bird
{
public:
    Bird_Red(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Skill();
};

#endif // BIRD_RED_H
