#include "gameviews.h"
#include <QTimer>
#include <QPainter>
#include"tower.h"
gameviews::gameviews(QWidget *parent) : QMainWindow(parent)
{
    wave=3;
    myblood=7;
    mymoney=100;
    lose=0;
    win=0;
  //回到主界面的按钮
    this->setFixedSize(2000,1500);
    buttons *backbu=new buttons(":/an.jpg");
    backbu->setParent(this);
    backbu->move(0,0);
    backbu->setFixedSize(60,60);
    connect(backbu,&buttons::clicked,this,[=](){
      emit back();
    });

//建塔的按钮
   buttons *set_tower=new buttons(":/an.jpg");//按钮的图片
   set_tower->setParent(this);
   set_tower->move(300,70);//按钮的位置
   set_tower->setFixedSize(40,40);//按钮的大
   connect(set_tower,&buttons::clicked,this,&gameviews::set_tower0);//将鼠标动作和按钮联系起来

   buttons *set_tower1=new buttons(":/an.jpg");//按钮的图片
   set_tower1->setParent(this);
   set_tower1->move(500,600);//按钮的位置
   set_tower1->setFixedSize(40,40);//按钮的大
   connect(set_tower1,&buttons::clicked,this,&gameviews::set_tower1);//将鼠标动作和按钮联系起来

   buttons *set_tower2=new buttons(":/an.jpg");//按钮的图片
   set_tower2->setParent(this);
   set_tower2->move(1300,500);//按钮的位置
   set_tower2->setFixedSize(40,40);//按钮的大
   connect(set_tower2,&buttons::clicked,this,&gameviews::set_tower2);//将鼠标动作和按钮联系起来

   buttons *set=new buttons(":/an.jpg");//按钮的图片
   set->setParent(this);
   set->move(800,800);//按钮的位置
   set->setFixedSize(400,400);//按钮的大
   connect(set,&buttons::clicked,this,&gameviews::addobject);

    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&gameviews::updating);
            timer->start(10);
    QTimer::singleShot(300, this, SLOT(start()));

    gettowerposition();

}

void gameviews::paintEvent(QPaintEvent *){

    QPainter painter(this);


       QPixmap pixmap(":/map11.jpg");
       painter.drawPixmap(0,0,this->width(),this->height(),pixmap);//背景


       foreach(const towerposition &towerpos, towerpositions)
           towerpos.draw(&painter);

      foreach(tower *tower,towers)
          tower->draw(&painter);

      foreach(objectx *object,object_list)
         object->draw(&painter);
      foreach(enemy *enemy0,enemys)
          enemy0->draw(&painter);



}
//建塔
void gameviews::set_tower0(){
    tower *tower2=new tower(QPoint(300,70),":/red.jpg");//第一个塔的建立
    towers.push_back(tower2);
    update();

}
void gameviews::set_tower1(){
    tower *tower3=new tower(QPoint(500,600),":/red.jpg");//第一个塔的建立
     towers.push_back(tower3);
    update();
}
void gameviews::set_tower2(){
    tower *tower4=new tower(QPoint(1200,500),":/red.jpg");//第一个塔的建立
     towers.push_back(tower4);
    update();

}

void gameviews::addobject(){
    objectx *object =new objectx(QPoint(0,200),QPoint(2000,200),":/xyy.jpg");
    object_list.push_back(object);
    object->move();
    update();
}

void gameviews::updating(){
    update();
}

void gameviews::addbullet(bullet *bullet2)
{
    Q_ASSERT(bullet2);

    bullets.push_back(bullet2);
}

void gameviews::getmoney(int money)
{
    mymoney+=money;
    update();
}

void gameviews::start()
{
   // for (int i = 0; i < 10; ++i)
   //  {
         enemy *enemy1 = new enemy(QPoint(0,0),QPoint(2000,200),":/xyy.png");
         enemys.push_back(enemy1);
         QTimer::singleShot(40, enemy1, SLOT(run()));
   //  }
}

void gameviews::gettowerposition(){

        QPoint positions[] =
        {
            QPoint(65, 220),
            QPoint(155, 220)};
        int len	= sizeof(positions) / sizeof(positions[0]);

        for (int i = 0; i < len; ++i)
            towerpositions.push_back(positions[i]);
}
