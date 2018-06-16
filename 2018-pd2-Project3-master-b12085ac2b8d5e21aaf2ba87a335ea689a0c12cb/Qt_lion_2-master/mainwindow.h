#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "bullet.h"

#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


//    virtual void mouseReleaseEvent(QMouseEvent *e);

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
//    virtual void mousePressEvent(QMouseEvent *e);
    void longPressB();
    void enemy();
    bool isCollision(QGraphicsPixmapItem *p, bullet *b);
    bool eventFilter(QObject *obj,QEvent *event);
    void test(QObject *b);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;
    QTimer *timer;
    QTimer *eTimer;
    QTimer *bTimer;
};

#endif // MAINWINDOW_H














