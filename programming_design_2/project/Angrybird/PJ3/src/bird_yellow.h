#ifndef BIRD_YELLOW_H
#define BIRD_YELLOW_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_YELLOW_DENSITY 50.0f
#define BIRD_YELLOW_FRICTION 0.2f
#define BIRD_YELLOW_RESTITUTION 0.5f

class Bird_Yellow : public Bird
{
public:
    Bird_Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Skill();
private:
    QGraphicsScene *Scene_Yellow;
};

#endif // BIRD_YELLOW_H
