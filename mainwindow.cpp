#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "asteroid.h"
#include <bullet.h>
#include <spaceship.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
                                   //ширина, висота, батько
    scene = new QGraphicsScene(0,0,800,600, this);

    //липкий фокус.
    //якщо викличеться якийсь фокус він вже залишиться
    //і не буде розфокусовуватись
    scene->setStickyFocus(true);

    scene->setBackgroundBrush(Qt::gray);

    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

    scene->addItem(new SpaceShip(scene->height()));


//анімація
    animationTimer = new QTimer(this);
    //коли таймер спрацьовує сцена змінюється
    connect(animationTimer, SIGNAL(timeout()),
           scene, SLOT(advance()));

    //швидкість 60 кадрів в сек
    animationTimer->start(1000/60);


    //створення нового обєкту
    generatorTimer = new QTimer (this);
    //якщо таймер спрацбовує обєкт свторюється
    connect(generatorTimer, SIGNAL (timeout()),
            this, SLOT (onGenerate()));
    //обєкт падає щосекунди
    generatorTimer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGenerate()
{
    //новий елемент створюєтсья по ширині сцени
    scene->addItem(new Asteroid(scene->sceneRect().width()));
}
