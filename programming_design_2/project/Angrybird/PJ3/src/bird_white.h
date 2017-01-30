#ifndef BIRD_WHITE_H
#define BIRD_WHITE_H

#include <gameitem.h>
#include <bird.h>
#include <bird_black.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <windows.h>
#include <unistd.h>

#define BIRD_WHITE_DENSITY 50.0f
#define BIRD_WHITE_FRICTION 0.2f
#define BIRD_WHITE_RESTITUTION 0.5f

class Bird_White : public Bird
{
public:
    Bird_White(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Skill();
    virtual void Delete_Bird();
    virtual void Skill2();
    virtual QPointF Get_Position_Px();
private:
    Bird *Bomb;
    b2World *World_White;
    QGraphicsScene *Scene_White;
    QTimer *Timer_White;
    bool Is_Skill=false;
};

#endif // BIRD_WHITE_H
