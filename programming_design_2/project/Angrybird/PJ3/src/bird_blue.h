#ifndef BIRD_BLUE_H
#define BIRD_BLUE_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_BLUE_DENSITY 50.0f
#define BIRD_BLUE_FRICTION 0.2f
#define BIRD_BLUE_RESTITUTION 0.5f

class Bird_Blue : public Bird
{
public:
    Bird_Blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Skill();
    virtual void Delete_Bird();
private:
    Bird * Skill_Bird[2];
    b2World *World_Blue;
    QGraphicsScene *Scene_Blue;
    QTimer *Timer_Blue;
    bool Is_Skill=false;
};

#endif // BIRD_Blue_H
