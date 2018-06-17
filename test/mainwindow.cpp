#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1200, 800)),
    timer(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player = new QGraphicsPixmapItem(QPixmap("../test/res/red_bullet.png"));
    scene->addItem(player);
    player->setPos(600 - player->pixmap().height()/2, 800 - player->pixmap().height());
    timer->start(10);

    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setFocusProxy(0);
    bTimer = new QTimer;
    connect(bTimer, SIGNAL(timeout()), this, SLOT(QQQ()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::eventFilter(QObject *,QEvent *event){
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        bTimer->start(500);
        qDebug()<<"b"<<endl;
        return false;
        break;
    case QEvent::MouseButtonRelease:
        bTimer->stop();
        qDebug() << "a" << endl;
        return false;
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
void MainWindow::QQQ(){
    qDebug() << "555";
}
