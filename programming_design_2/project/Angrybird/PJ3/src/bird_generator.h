#ifndef BIRD_GENERATOR_H
#define BIRD_GENERATOR_H

#include <bird.h>
#include <bird_blue.h>
#include <bird_red.h>
#include <bird_yellow.h>
#include <bird_white.h>
#include <bird_black.h>

Bird * bird_generator(QTimer *timer, b2World *world, QGraphicsScene *scene, float pos_y, int &bird_type);

#endif // BIRD_GENERATOR_H
