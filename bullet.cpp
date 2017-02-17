#include "bullet.h"
#include "asteroid.h"

#include <QBrush>
#include <QPen>

Bullet::Bullet(QPointF initPos, QGraphicsItem *parent)
    :QGraphicsLineItem(parent)
{
    //швидкість пулі
    yspeed = BULLET_SPEED;
    //встановлюємо олівець, 3 - ширина лінії
    setPen(QPen(QBrush(Qt::red),3));
    //встановлюємо геометрію лінії
   //летить вверх по осі y до 0, тому -BULLET_LENGHT
    setLine(0, 0, 0, -BULLET_LENGHT);

    //зміщення елемента відносно батька
    setPos(initPos);

}

void Bullet::advance(int phase)
{
    //метод викликається двічі один з phase =0,
    //а другий з phase =1
    if(!phase)
    {
        //повертає список графічних елементів з якими зіткнувся
        //нащ графічний елемент
        foreach (QGraphicsItem *item, collidingItems())
        {
             //мітим що елемент має бути видалений і
            //в advance астероїда видаляємо його повністю
            //мітимо за допомогою setData -
            //дані по ключу для елемента
            if(item->type() == Asteroid::Type)
            {
                item->setData(0,true);
                setData(0,true);
            }
        }
    }
    else
    {
        moveBy(0, -yspeed);
        if(data(0).toBool() || y()==0)
        {
            delete this;
        }
    }
}

