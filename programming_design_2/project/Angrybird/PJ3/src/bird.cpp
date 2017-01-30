#include "bird.h"

Bird::Bird(b2World *world):GameItem(world)
{
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void Bird::Set_Transform(b2Vec2 position)
{
    position.x=(position.x>=2.2)?position.x:2.2;
    position.x=(position.x<=3.8)?position.x:3.8;
    position.y=(position.y>=3.2)?position.y:3.2;
    position.y=(position.y>=4.8)?position.y:4.8;
    g_body->SetTransform(position,g_body->GetAngle());
}

void Bird::Init_Position()
{
    g_body->SetTransform(b2Vec2(3,10),0);
    g_body->SetLinearVelocity(b2Vec2(0,-0.1));
}

void Bird::Kikk_Gravity()
{
    g_body->SetGravityScale(0.0);
}

void Bird::Add_Gravity()
{
    g_body->SetGravityScale(1.0);
}

void Bird::Set_Pixmap(QPixmap pixmap)
{
    g_pixmap.setPixmap(pixmap);
}

b2Vec2 Bird::Get_Velocity()
{
    return g_body->GetLinearVelocity();
}

b2Vec2 Bird::Get_Position()
{
    return g_body->GetPosition();
}
