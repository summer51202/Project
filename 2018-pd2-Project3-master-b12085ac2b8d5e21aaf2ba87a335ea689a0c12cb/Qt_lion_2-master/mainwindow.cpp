#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMouseEvent>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1200, 800)),
    timer(new QTimer),
    eTimer(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player = new QGraphicsPixmapItem(QPixmap(":/res/red_bullet.png"));
    scene->addItem(player);
    player->setPos(600 - player->pixmap().height()/2, 800 - player->pixmap().height());
    timer->start(10);
    eTimer->start(1500);
    qsrand(time(NULL));
    bTimer = new QTimer;
    connect(eTimer, SIGNAL(timeout()), this, SLOT(enemy()));
    connect(bTimer, SIGNAL(timeout()), this, SLOT(longPressB()));
    //solution to cannot get mouseReleasedEvent
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setFocusProxy(0);
//    connect(timer, SIGNAL(timeout()), this, SLOT(test()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "fuc,";
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        player->setPos(player->x(), player->y() - 10);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        player->setPos(player->x(), player->y() + 10);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        player->setPos(player->x() - 10, player->y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        player->setPos(player->x() + 10, player->y());
        break;
    }
}
void MainWindow::longPressB(){
    bullet *b = new bullet;
    bullet *b1 = new bullet;
    bullet *b2 = new bullet;

    if(qrand() % 2 == 0) {
        b->setPixmap(QPixmap(":/res/black_bullet.png").scaled(25, 25));
        b1->setPixmap(QPixmap(":/res/black_bullet.png").scaled(25, 25));
        b2->setPixmap(QPixmap(":/res/black_bullet.png").scaled(25, 25));
    }
    else {
        b->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
        b1->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
        b2->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
    }
    b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width(), player->y() - b->pixmap().height());
    b1->setPos(player->x() + player->pixmap().width() / 2 - b1->pixmap().width() / 2, player->y() - b1->pixmap().height());
    b2->setPos(player->x() + player->pixmap().width() / 2, player->y() - b2->pixmap().height());
    b->setNavig(- b->pixmap().width() / 24);
    b1->setNavig(0);
    b2->setNavig(b2->pixmap().width() / 24);
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
    b1->connect(timer, SIGNAL(timeout()), b1, SLOT(fly()));
    b2->connect(timer, SIGNAL(timeout()), b2, SLOT(fly()));
//    b->connect(timer, SIGNAL(timeout()), b, SLOT(isCollision(player, b)));
//    b1->connect(timer, SIGNAL(timeout()), b1, SLOT(isCollision(player, b1)));
//    b2->connect(timer, SIGNAL(timeout()), b2, SLOT(isCollision(player, b2)));

    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b1));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b2));
}
//void MainWindow::mousePressEvent(QMouseEvent *e)
//{
//    bTimer->start(500);
//    qDebug()<<"b"<<endl;
//}

//void MainWindow::mouseReleaseEvent(QMouseEvent *e)
//{
//    bTimer->stop();
//    qDebug() << "a" << endl;
//}

void MainWindow::enemy(){
    bullet *b = new bullet;
    QString a = "a";
    QSignalMapper *bMapper = new QSignalMapper(this);

    b->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
    b->setPos((qrand() % 12)*100, 0);
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly2()));
    connect(timer, SIGNAL(timeout()), bMapper, SLOT(map()));
    bMapper->setMapping(timer, b);
    connect(bMapper, SIGNAL(mapped(QObject*)), this, SLOT(test(QObject*)));
//    connect(this, SIGNAL(test()), this, SLOT(isCollision));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}

bool MainWindow::isCollision(QGraphicsPixmapItem *p, bullet *b){
    double distance = sqrt((p->x()-b->x()) * (p->x()-b->x()) + (p->y()-b->y()) * (p->y()-b->y()));
    if(distance <= (p->pixmap().width()/2 + b->pixmap().width()/2)){
        qDebug() << "Collision!";
        return true;
    }

}

void MainWindow::test(QObject *b){
//     qDebug() << "test!";

    if(isCollision(player, dynamic_cast<bullet*>(b))){
        delete b;
        delete player;
        player = new QGraphicsPixmapItem(QPixmap(":/res/red_bullet.png"));
        scene->addItem(player);
        player->setPos(600 - player->pixmap().height()/2, 800 - player->pixmap().height());
    }
}

bool MainWindow::eventFilter(QObject *obj,QEvent *event){
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        bTimer->start(200);
        qDebug()<<"b"<<endl;
        return true;
        break;
    case QEvent::MouseButtonRelease:
        bTimer->stop();
        qDebug() << "a" << endl;
        return true;
        break;
//    case value:

//        break;
//    case value:

//        break;
    default:
        return false;
        break;
    }
}
































