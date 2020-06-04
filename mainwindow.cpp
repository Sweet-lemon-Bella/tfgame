#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include  <QPushButton>
#include <QDebug>
#include "buttons.h"
#include "gameviews.h"
class bullet;
class tower;
class enemy;
class objectx;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //主界面大小
    this->setFixedSize(2000,1500);
    ui->setupUi(this);


    //主界面按钮
    buttons *bu=new buttons(":/xyy.jpg");
    bu->setParent(this);
    bu->move(500,400);
    connect(bu,&buttons::clicked,this,&QMainWindow::close);

    buttons *bu1=new buttons(":/htl.jpg");
    bu1->setParent(this);
    bu1->move(900,400);
    connect(bu1,&buttons::clicked,this,&QMainWindow::close);


    //游戏界面按钮，view1是gameviews的一个指针
    gameviews *view1=new gameviews;
    connect(bu,&QPushButton::clicked,this,[=](){
         this->hide();
        view1->show();

    });
    //主界面和游戏界面1即view1的切换，通过一个按钮来实现
   connect(view1,&gameviews::back,this,[=](){
        view1->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//主界面的背景
void MainWindow::paintEvent(QPaintEvent*){
   QPainter painter(this);
   QPixmap pixmap(":/ycc.jpg");
   painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
