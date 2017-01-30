#ifndef BIRD_BLACK_H
#define BIRD_BLACK_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_BLACK_DENSITY 50.0f
#define BIRD_BLACK_FRICTION 0.2f
#define BIRD_BLACK_RESTITUTION 0.5f

class Bird_Black : public Bird
{
public:
    Bird_Black(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Skill();
    virtual void Delete_Bird();
    virtual QPointF Get_Position_Px();
private:
    Bird *Bomb[8];
    b2World *World_Black;
    QGraphicsScene *Scene_Black;
    QTimer *Timer_Black;
    bool Is_Skill=false;
    int v[8][2]={{50,0},{30,-30},{0,-50},{-30,-30},{-50,0},{-30,30},{0,50},{30,30}};
    int pos[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
};

#endif // BIRD_BLACK_H
