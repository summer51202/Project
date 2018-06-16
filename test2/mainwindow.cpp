#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSignalMapper>
#include <QList>

//features: hits, 2 versions, special skill bullet, starting animation
//TODO: bullets collision, enemy 2(boss), score
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 900, 860)),
    player(new Player),
    timer(new QTimer),
    bTimer(new QTimer),
    aTimer(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player->GPixmap.setPixmap(QPixmap("../test2/player.png").scaled(100,100));
    player->GPixmap.setPos(450 - player->GPixmap.pixmap().width()/2, 800 - player->GPixmap.pixmap().width()/2);
    scene->addItem(&player->GPixmap);
    timer->start(10);
    aTimer->start(1500);
    connect(bTimer, SIGNAL(timeout()), this, SLOT(longPressB()));
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setFocusProxy(0);
    qsrand(time(NULL));
    connect(aTimer, SIGNAL(timeout()), this, SLOT(enemyAppear()));

//    connect(boomTimer, SIGNAL(timeout()), this, SLOT(booming()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::longPressB(){
    bullet *b = new bullet;
    b->setPixmap(QPixmap("../test2/bullet.png").scaled(10, 50));
    b->setPos(player->GPixmap.x() + player->GPixmap.pixmap().width() / 2 - b->pixmap().width() / 2, player->GPixmap.y() - b->pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
    scene->addItem(b);
}

bool MainWindow::eventFilter(QObject *obj,QEvent *event){

    QMouseEvent *e = static_cast<QMouseEvent*>(event);
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        if(QApplication::mouseButtons()==Qt::LeftButton){
            bTimer->start(200);
            startMove = true;
            qDebug()<<"b"<<endl;
        }
        return true;
        break;
    case QEvent::MouseButtonRelease:
        bTimer->stop();
        qDebug() << "a" << endl;
        startMove = false;
        return true;
        break;
    case QEvent::MouseMove:
        if(startMove){
            qDebug() << "oooooooo";
            if(QApplication::mouseButtons()==Qt::LeftButton){
                player->GPixmap.setPos(e->pos().x() - player->GPixmap.pixmap().width()/2, e->pos().y() - player->GPixmap.pixmap().height()/2);
            }
        }
        return true;
        break;
    default:
        return false;
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        player->GPixmap.setPos(player->GPixmap.x(), player->GPixmap.y() - 10);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        player->GPixmap.setPos(player->GPixmap.x(), player->GPixmap.y() + 10);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        player->GPixmap.setPos(player->GPixmap.x() - 10, player->GPixmap.y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        player->GPixmap.setPos(player->GPixmap.x() + 10, player->GPixmap.y());
        break;
    }
}

void MainWindow::enemyAppear(){
    Enemy *e = new Enemy(this) ;
    connect(e->eMapper, SIGNAL(mapped(QObject*)), this, SLOT(mapToCollision(QObject*)));
    scene->addItem(&e->GPixmap);
}

bool MainWindow::isCollisionToPlayer(QGraphicsPixmapItem *e, QGraphicsPixmapItem *p){
    QList<QGraphicsItem*> collision = scene->collidingItems(e);
    for(int i = 0; i < collision.size(); i++){
        // why "==" can work? =="
        if(collision.at(i) == p){
            return true;
        }

    }
    return false;
}

bool MainWindow::isCollisionToBullets(QGraphicsPixmapItem *e){
    QList<QGraphicsItem*> collision = scene->collidingItems(e);
    for(int i = 0; i < collision.size(); i++){
        // why "==" can work? =="
        bullet *b;
        // can work? =="
        if(b = dynamic_cast<bullet*>(collision.at(i))){
            scene->removeItem(collision.at(i));
            delete collision.at(i);
            qDebug() << "buuuu";
            return true;
        }

    }
    return false;
}

void MainWindow::mapToCollision(QObject *enemy){
    Enemy* a;
    if(a = dynamic_cast<Enemy*>(enemy)){
        if(isCollisionToPlayer(&a->GPixmap, &player->GPixmap)){
//            collisionAnimation(player->GPixmap.pos());
            // stop movement and shooting when player died
            startMove = false;
            bTimer->stop();
            delete enemy;
            scene->removeItem(&player->GPixmap);
            delete player;
            player = new Player;
            player->GPixmap.setPixmap(QPixmap("../test2/player.png").scaled(100, 100));
            scene->addItem(&player->GPixmap);
            player->GPixmap.setPos(450 - player->GPixmap.pixmap().height()/2, 800 - player->GPixmap.pixmap().height());
            // end this function if colliding with player first
            return;
        }
        if(isCollisionToBullets(&a->GPixmap)){
            delete enemy;
        }
    } else{
        qDebug() << "no";
    }
}

//void MainWindow::collisionAnimation(QGraphicsPixmapItem *p){
//    boom = new QGraphicsPixmapItem;
//    boomTimer = new QTimer;
//    connect(boomTimer, SIGNAL(timeout()), this, SLOT(booming()));
//    boomTimer->start(50);
//    boomSize = p->scale();
//    boom->setPixmap(QPixmap("../test2/player.png").scaled(0, 0));
//    boom->setPos(p->pos().x() + p->pixmap().width()/2, p->pos().y() + p->pixmap().height()/2);
//    boomState = 0;
//}

//void MainWindow::booming(){
//    ++boomState;
//    boom->setScale(boomSize/10 * boomState);
//    boom->setPos();
//}

//void MainWindow::collisionAnimation(QPointF pos){
//    x = pos.x();
//    y = pos.y();
//    boom = new QGraphicsPixmapItem;
//    boomTimer = new QTimer;
//    boomTimer->start(50);
//    connect(boomTimer, SIGNAL(timeout()), this, SLOT(booming()));
//    boomState = 0;
//    boom->setPixmap(QPixmap("../test2/boom.png").scaled(50, 50));
//    boom->setPos(x+ GPixmap.pixmap().width()/2, y+ GPixmap.pixmap().height()/2);
//    scene()->addItem(boom);
//    qDebug() << "gggggg";
//}


//void MainWindow::booming(){
//    ++boomState;
//    qDebug() << "ssssssssssssss";
//    qDebug() << boomState;
//    boom->setScale(GPixmap.scale()/10 * boomState);
//    boom->setPos(x + GPixmap.pixmap().width()/2 * (10 - boomState)/10, y + GPixmap.pixmap().height()/2 * (10 - boomState)/10);
//    if(boomState == 10){
//        boomTimer->stop();
//        delete boomTimer;
//        scene->removeItem(boom);
//        delete boom;
//    }
//}
