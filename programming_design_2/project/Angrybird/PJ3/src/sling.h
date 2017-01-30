#ifndef SLING_H
#define SLING_H

#include <gameitem.h>
#include <QGraphicsScene>

class Sling : public GameItem
{
public:
    Sling(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void Set_Transform(float pos_y);
    virtual ~Sling(){}
};

#endif // SLING_H
