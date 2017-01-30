#include "bird_black.h"

Bird_Black::Bird_Black(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(world)
{
    World_Black=world;
    Scene_Black=scene;
    Timer_Black=timer;
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
    fixturedef.density = BIRD_BLACK_DENSITY;
    fixturedef.friction = BIRD_BLACK_FRICTION;
    fixturedef.restitution = BIRD_BLACK_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird_Black::Skill()
{
    for(int i=0;i<8;++i){
        Bomb[i] = new Bird_Black(g_body->GetPosition().x+pos[i][0],g_body->GetPosition().y+pos[i][1],0.27,Timer_Black,QPixmap(":/Background/Nothing.png").scaled(Scene_Black->height()/9.0,Scene_Black->height()/9.0),World_Black,Scene_Black);
        Bomb[i]->setLinearVelocity(b2Vec2(v[i][0],v[i][1]));
    }
    Is_Skill=true;
}

void Bird_Black::Delete_Bird()
{
    if(Is_Skill){
        delete Bomb[0];
        delete Bomb[1];
        delete Bomb[2];
        delete Bomb[3];
        delete Bomb[4];
        delete Bomb[5];
        delete Bomb[6];
        delete Bomb[7];
    }
}

QPointF Bird_Black::Get_Position_Px()
{
    return mappedPoint;
}
