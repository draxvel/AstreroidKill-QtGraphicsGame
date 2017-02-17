#include "spaceship.h"
#include "mainwindow.h"
#include "bullet.h"

SpaceShip::SpaceShip(int sceneHight):QGraphicsPixmapItem(0)
{
    //завантажуємо фото космічного коробля
    setPixmap(QPixmap(":/images/spaceship.png").scaled(50,80));

    //встановлюємо позицію
    setPos(0, sceneHight-pixmap().height());

    //щоб клавіші вловлювали яким елементом управляти треба
    //встановити на певний елемент фокус
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void SpaceShip::advance(int phase)
{
    if(phase)
    {
        moveBy(xspeed, 0);
    }
}

void SpaceShip::keyPressEvent(QKeyEvent *event)
{
    //обробка клавіш left і right
    switch (event->key())
    {
        case Qt::Key_Left:
            xspeed=-SPACESHIP_SPEED;
            break;
        case Qt::Key_Right:
            xspeed=SPACESHIP_SPEED;
            break;
        case Qt::Key_Space:
        //передаємо в конструктор точку носика короабля
        //для цього трансформуємо точку в систему координат сцени

           scene()->addItem( new Bullet(mapToScene(QPointF(pixmap().width()/2, 0)),
                       0));
        break;
        default:
            break;
    }
}

void SpaceShip::keyReleaseEvent(QKeyEvent *event)
{
    //занулюємо, щоб корабель зупинявся
    switch (event->key())
    {
        case Qt::Key_Left:
            xspeed=0;
            break;
        case Qt::Key_Right:
            xspeed=0;
            break;
        default:
            break;
    }
}
