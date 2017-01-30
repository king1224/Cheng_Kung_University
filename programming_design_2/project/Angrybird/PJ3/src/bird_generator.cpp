#include "bird_generator.h"

Bird * bird_generator(QTimer *timer, b2World *world, QGraphicsScene *scene, float pos_y, int &bird_type){
    Bird *ptr;

    bird_type=rand()%5;

    switch(bird_type){
        case 0:
            ptr = new Bird_Red(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_Red.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
        break;
        case 1:
            ptr = new Bird_Blue(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_Blue.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
        break;
        case 2:
            ptr = new Bird_Yellow(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_Yellow1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
        break;
        case 3:
            ptr = new Bird_White(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_White1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
        break;
        case 4:
            ptr = new Bird_Black(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_Black1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
        break;
        default:
            ptr = new Bird_Red(0.5,pos_y,0.27,timer,QPixmap(":/Bird/Bird_Red.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    }

    return ptr;
}
