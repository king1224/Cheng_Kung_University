#include "wall_glass.h"

Wall_Glass::Wall_Glass(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Wall(world)
{
    Scene_Glass=scene;
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(-1,4);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/77,h/7);
    b2FixtureDef fixturedef;
    fixturedef.shape=&bodyBox;
    fixturedef.density = WALL_GLASS_DENSITY;
    fixturedef.friction = WALL_GLASS_FRICTION;
    fixturedef.restitution = WALL_GLASS_RESTITUTION;
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

int Wall_Glass::Kill()
{
    if(Hit==1&&(g_body->GetLinearVelocity().x>0.5||g_body->GetLinearVelocity().y>0.25||g_body->GetPosition().y<4.78)) return 2;
    if(g_body->GetLinearVelocity().x>2||g_body->GetLinearVelocity().y>1){
        g_pixmap.setPixmap(QPixmap(":/Background/Wall_Glass2.png").scaled(Scene_Glass->width()/48.0,Scene_Glass->height()/2.7));
        ++Hit;
        return 1;
    }
    return 0;
}
