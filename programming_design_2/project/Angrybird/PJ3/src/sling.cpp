#include "sling.h"
#include <iostream>
Sling::Sling(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w-2,h+2);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h-0.5);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&g_pixmap);
    paint();
}

void Sling::Set_Transform(float pos_y)
{
    g_body->SetTransform(b2Vec2(g_body->GetPosition().x,pos_y),g_body->GetAngle());
}
