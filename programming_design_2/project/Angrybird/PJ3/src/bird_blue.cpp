#include "bird_blue.h"

Bird_Blue::Bird_Blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(world)
{
    World_Blue=world;
    Scene_Blue=scene;
    Timer_Blue=timer;
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
    fixturedef.density = BIRD_BLUE_DENSITY;
    fixturedef.friction = BIRD_BLUE_FRICTION;
    fixturedef.restitution = BIRD_BLUE_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird_Blue::Skill()
{
    Skill_Bird[0] = new Bird_Blue(g_body->GetPosition().x,g_body->GetPosition().y+1,0.27,Timer_Blue,QPixmap(":/Bird/Bird_Blue.png").scaled(Scene_Blue->height()/9.0,Scene_Blue->height()/9.0),World_Blue,Scene_Blue);
    Skill_Bird[1] = new Bird_Blue(g_body->GetPosition().x,g_body->GetPosition().y-1,0.27,Timer_Blue,QPixmap(":/Bird/Bird_Blue.png").scaled(Scene_Blue->height()/9.0,Scene_Blue->height()/9.0),World_Blue,Scene_Blue);
    Skill_Bird[0] -> setLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x-1,g_body->GetLinearVelocity().y+3));
    Skill_Bird[1] -> setLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x-1,g_body->GetLinearVelocity().y-3));
    Is_Skill=true;
}

void Bird_Blue::Delete_Bird()
{
    if(Is_Skill){
        Skill_Bird[0]->Set_Transform(b2Vec2(100,100));
        Skill_Bird[1]->Set_Transform(b2Vec2(90,90));
        delete Skill_Bird[0];
        delete Skill_Bird[1];
    }
}
