#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <iostream>

class Bird : public GameItem
{
public:
    Bird(b2World *world);
    void setLinearVelocity(b2Vec2 velocity);
    void Set_Transform(b2Vec2 position);
    void Init_Position();
    void Kikk_Gravity();
    void Add_Gravity();
    void Set_Pixmap(QPixmap pixmap);
    b2Vec2 Get_Velocity();
    b2Vec2 Get_Position();
    virtual QPointF Get_Position_Px(){return QPointF();}
    virtual void Delete_Bird(){}
    virtual void Skill() = 0;
    virtual void Skill2(){}
};

#endif // BIRD_H
