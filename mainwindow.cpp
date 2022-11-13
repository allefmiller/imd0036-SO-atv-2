#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,303,30);
    trem2 = new Trem(2,484,30);
    trem3 = new Trem(3,213,220);
    trem4 = new Trem(4,390,220);
    trem5 = new Trem(5,570,220);

    path = qgetenv("PWD") + "/imd0036-SO-atv-2/";

    connect(trem1,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::updateInterface(int id, int x, int y, int direcao){
    switch(id){
    case 1:
        ui->trem1->setGeometry(x,y,41,41);
        trem1->setVelocidade(ui->slider_t1->value());

        if(direcao == 1)
           ui->trem1->setPixmap(QPixmap(path + "sprites/sprite-train-right.png"));
        else if(direcao == 2)
           ui->trem1->setPixmap(QPixmap(path + "sprites/sprite-train-down.png"));
        else if(direcao == 3)
           ui->trem1->setPixmap(QPixmap(path + "sprites/sprite-train-left.png"));
        else
           ui->trem1->setPixmap(QPixmap(path + "sprites/sprite-train-up.png"));
        break;
    case 2:
        ui->trem2->setGeometry(x,y,41,41);
        trem2->setVelocidade(ui->slider_t2->value());

        if(direcao == 1)
           ui->trem2->setPixmap(QPixmap(path + "sprites/sprite-train-right.png"));
        else if(direcao == 2)
           ui->trem2->setPixmap(QPixmap(path + "sprites/sprite-train-down.png"));
        else if(direcao == 3)
           ui->trem2->setPixmap(QPixmap(path + "sprites/sprite-train-left.png"));
        else
           ui->trem2->setPixmap(QPixmap(path + "sprites/sprite-train-up.png"));
        break;
    case 3:
        ui->trem3->setGeometry(x,y,41,41);
        trem3->setVelocidade(ui->slider_t3->value());

        if(direcao == 1)
           ui->trem3->setPixmap(QPixmap(path + "sprites/sprite-train-right.png"));
        else if(direcao == 2)
           ui->trem3->setPixmap(QPixmap(path + "sprites/sprite-train-down.png"));
        else if(direcao == 3)
           ui->trem3->setPixmap(QPixmap(path + "sprites/sprite-train-left.png"));
        else
           ui->trem3->setPixmap(QPixmap(path + "sprites/sprite-train-up.png"));
        break;
    case 4:
        ui->trem4->setGeometry(x,y,41,41);
        trem4->setVelocidade(ui->slider_t4->value());

        if(direcao == 1)
           ui->trem4->setPixmap(QPixmap(path + "sprites/sprite-train-right.png"));
        else if(direcao == 2)
           ui->trem4->setPixmap(QPixmap(path + "sprites/sprite-train-down.png"));
        else if(direcao == 3)
           ui->trem4->setPixmap(QPixmap(path + "sprites/sprite-train-left.png"));
        else
           ui->trem4->setPixmap(QPixmap(path + "sprites/sprite-train-up.png"));
        break;
    case 5:
        ui->trem5->setGeometry(x,y,41,41);
        trem5->setVelocidade(ui->slider_t5->value());

        if(direcao == 1)
           ui->trem5->setPixmap(QPixmap(path + "sprites/sprite-train-right.png"));
        else if(direcao == 2)
           ui->trem5->setPixmap(QPixmap(path + "sprites/sprite-train-down.png"));
        else if(direcao == 3)
           ui->trem5->setPixmap(QPixmap(path + "sprites/sprite-train-left.png"));
        else
           ui->trem5->setPixmap(QPixmap(path + "sprites/sprite-train-up.png"));
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
