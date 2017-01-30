#include "wall_fake.h"

Wall_Fake::Wall_Fake(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Wall(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h+1);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&g_pixmap);
    paint();
}

void Wall_Fake::Set_Transform(float pos_x)
{
    g_body->SetTransform(b2Vec2(pos_x,g_body->GetPosition().y),g_body->GetAngle());
}
