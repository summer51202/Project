#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>

#include "Player.h"
#include "bullet.h"
#include "enemy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent *e);
    void longPressB();
    bool eventFilter(QObject *obj,QEvent *event);
    void enemyAppear();
    bool isCollisionToPlayer(QGraphicsPixmapItem *e, QGraphicsPixmapItem *p);
    void mapToCollision(QObject *enemy);
    bool isCollisionToBullets(QGraphicsPixmapItem *e);
    void collisionAnimation(QPointF pos);
    void booming();
    void showHeart(int l);
    void showScore(int s);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *player;
    QTimer *timer;
    QTimer *bTimer;
    QTimer *aTimer;
    bool startMove = false;
    float_t x;
    float_t y;
    QGraphicsPixmapItem *boom;
    QTimer *boomTimer;
    int boomState;
    int score = 0;
};

#endif // MAINWINDOW_H
