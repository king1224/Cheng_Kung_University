#include "wall.h"

Wall::Wall(b2World *world):GameItem(world)
{
}

void Wall::Set_Transform(float angel)
{
    g_body->SetTransform(g_body->GetPosition(),angel);
}

int Wall::Kill()
{
    if(Hit==1&&g_body->GetLinearVelocity().x>0.5) return 2;
    if(g_body->GetLinearVelocity().x>2){
        ++Hit;
        return 1;
    }
    return 0;
}
