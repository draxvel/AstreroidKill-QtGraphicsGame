#include "asteroid.h"
#include <mainwindow.h>

Asteroid::Asteroid(int xspread):QGraphicsPixmapItem(0)
{
/*
    //колір кожного разу інший
    QColor color = QColor(rand () % 255, rand () %255, rand () %255);
    //встановлюємо в пензлик наш колір
    setBrush(color);
    //прямокутник в який буде вписаний еліпс (це все ф-кції QGraphicsEllipseItem)
    setRect(0, 0, CIRCLE_SIZE, CIRCLE_SIZE);
*/

    //завантажуємо фото астероїдів
    setPixmap(QPixmap(":images/asteroid.png").scaled(50,50));


    //рандомна позиція x, а поясвлятись буде зверху тому y=0
    setPos(rand ()% (xspread - pixmap().width()), 0);
}

void Asteroid::advance(int phase)
{
    //щоб елемент рухався в два рази повільніше
    if(phase)
    {
        moveBy(0, yspeed);
            if(data(0).toBool() || y()==scene()->height()-100)
                delete this;
    }
}

void Asteroid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //при кліку видаляємо
    delete this;
}

int Asteroid::type() const
{
    return Type;
}
