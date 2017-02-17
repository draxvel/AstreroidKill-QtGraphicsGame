#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsLineItem>
#include <QGraphicsItem>

#define BULLET_LENGHT 10
#define BULLET_SPEED 4


class Bullet:public QGraphicsLineItem
{
public:
    //поч положення пулі і батьківський граф елемент
    Bullet(QPointF initPos, QGraphicsItem* parent);
private:
    int yspeed;


    // QGraphicsItem interface
public:
    virtual void advance(int phase);
};




#endif // BULLET_H
