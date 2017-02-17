#ifndef ASTEROID_H
#define ASTEROID_H

#define CIRCLE_SIZE 50

#include <QGraphicsPixmapItem>

//астероїд
class Asteroid : public QGraphicsPixmapItem
{
public:
//тип
enum {Type = UserType+1};

    //xspread - розкид по осі x, де може бути створенний круг
    Asteroid(int xspread);

    // QGraphicsItem interface
public:
    virtual void advance(int phase);
private:
    int yspeed = 2;

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // QGraphicsItem interface
public:
    virtual int type() const;
};



#endif // ASTEROID_H
