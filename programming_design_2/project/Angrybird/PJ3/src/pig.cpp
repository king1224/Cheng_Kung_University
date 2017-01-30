#include "pig.h"

Pig::Pig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    Scene_Pig=scene;
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius,radius);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius*3;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = PIG_DENSITY;
    fixturedef.friction = PIG_FRICTION;
    fixturedef.restitution = PIG_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

int Pig::Kill()
{
    if(Hit==1&&(g_body->GetLinearVelocity().x>0.5||g_body->GetLinearVelocity().y>0.25)) return 2;
    if((g_body->GetLinearVelocity().x>2||g_body->GetLinearVelocity().y>1)){
        g_pixmap.setPixmap(QPixmap(":/Bird/Pig2.png").scaled(Scene_Pig->height()/9.0,Scene_Pig->height()/9.0));
        ++Hit;
        return 1;
    }
    return 0;
}
