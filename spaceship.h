#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#define SPACESHIP_SPEED 3


//космічний корабель
class SpaceShip : public QGraphicsPixmapItem
{
public:
    SpaceShip(int sceneHight);
private:


    // QGraphicsItem interface
public:
    virtual void advance(int phase);

protected:
    //перезавантажений метод - кнопка натиснута
    virtual void keyPressEvent(QKeyEvent *event);
    //перезавантажений метод - кнопка відпущена
    virtual void keyReleaseEvent(QKeyEvent *event);

private:
    int xspeed = 0;
};

#endif // SPACESHIP_H
