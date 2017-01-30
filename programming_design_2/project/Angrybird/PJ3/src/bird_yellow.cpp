#include "bird_yellow.h"

Bird_Yellow::Bird_Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(world)
{
    Scene_Yellow=scene;
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

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
    fixturedef.density = BIRD_YELLOW_DENSITY;
    fixturedef.friction = BIRD_YELLOW_FRICTION;
    fixturedef.restitution = BIRD_YELLOW_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird_Yellow::Skill()
{
    g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x*3,g_body->GetLinearVelocity().y*3));
    g_pixmap.setPixmap(QPixmap(":/Bird/Bird_Yellow2.png").scaled(Scene_Yellow->height()/9.0,Scene_Yellow->height()/9.0));
}
