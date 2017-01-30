#include "bird_white.h"

Bird_White::Bird_White(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(world)
{
    World_White=world;
    Scene_White=scene;
    Timer_White=timer;
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
    fixturedef.density = BIRD_WHITE_DENSITY;
    fixturedef.friction = BIRD_WHITE_FRICTION;
    fixturedef.restitution = BIRD_WHITE_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird_White::Skill()
{
    Bomb = new Bird_Black(g_body->GetPosition().x,g_body->GetPosition().y-1,0.27,Timer_White,QPixmap(":/Bird/Bird_White2.png").scaled(Scene_White->height()/9.0,Scene_White->height()/9.0),World_White,Scene_White);
    Is_Skill=true;
}

void Bird_White::Delete_Bird()
{
    if(Is_Skill){
        Bomb->Delete_Bird();
        delete Bomb;
    }
}

void Bird_White::Skill2()
{
    if(Is_Skill){
        Bomb->Skill();
    }
}

QPointF Bird_White::Get_Position_Px()
{
    return Bomb->Get_Position_Px();
}
