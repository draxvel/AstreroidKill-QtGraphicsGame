#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QgraphicsItem>


#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onGenerate();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //для анімації
    QTimer *animationTimer;
    //для створення обєктів кожної секунди
    QTimer *generatorTimer;
};

#endif // MAINWINDOW_H
