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
//    friend class Player;
//    friend class bullet;
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
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *player;
    QTimer *timer;
    QTimer *bTimer;
    QTimer *aTimer;
    bool startMove = false;

};

#endif // MAINWINDOW_H
