#include "gameviews.h"
#include <QTimer>
#include <QPainter>
#include"tower.h"
gameviews::gameviews(QWidget *parent) : QMainWindow(parent)
{

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

   buttons *set=new buttons(":/fly.png");//按钮的图片
   set->setParent(this);
   set->move(800,800);//按钮的位置
   set->setFixedSize(400,400);//按钮的大
   connect(set,&buttons::clicked,this,&gameviews::addobject);

    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&gameviews::updating);
            timer->start(10);



}

void gameviews::paintEvent(QPaintEvent *){
    QPainter painter(this);


    QPixmap pixmap(":/ee.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);//背景

   foreach(tower *tower,towers)
       tower->draw(&painter);

   foreach(objectx *object,object_list)
       object->draw(&painter);
}
//建塔
void gameviews::set_tower0(){
    tower *tower2=new tower(QPoint(300,70),":/hah.png");//第一个塔的建立

    towers.push_back(tower2);
    update();

}
void gameviews::set_tower1(){
    tower *tower2=new tower(QPoint(500,600),":/hah.png");//第一个塔的建立
     towers.push_back(tower2);
    update();
}
void gameviews::set_tower2(){
    tower *tower2=new tower(QPoint(1200,500),":/hah.png");//第一个塔的建立
     towers.push_back(tower2);
    update();

}

void gameviews::addobject(){
    objectx *object =new objectx(QPoint(0,200),QPoint(2000,200),":/fly.png");
    object_list.push_back(object);
    object->move();
    update();
}

void gameviews::updating(){
    update();
}
/*int	  wave;
    int	  myblood;
    int	  mymoney;
    bool gameEnded;
    bool	gameWin;*/
void gameviews::removedenemy(enemy *enemy)
{
    Q_ASSERT(enemy);
    enemys.removeOne(enemy);
    delete enemy;
    if (enemys.empty())
    {
        ++wave;
        if (!loadwave())
        {
           gameWin = true;
        }
    }
}

bool gameviews::loadwave()
{
    if (wave>= 6)
        return false;
    int enemyStartInterval[] = { 100, 500, 600, 1000, 3000, 6000 };
    for (int i = 0; i < 6; ++i)
    {
        enemy *enemy1 = new enemy(QPoint(2000,300),":/xiong.png");
        enemys.push_back(enemy1);
        QTimer::singleShot(enemyStartInterval[i], enemy1, SLOT(doActivate()));
    }
    return true;
}
void gameviews::addbullet(bullet *bullet2)
{
    Q_ASSERT(bullet2);

    bullets.push_back(bullet2);
}void gameviews::getmoney(int gold)
{
    mymoney+=mymoney;
    update();
}
