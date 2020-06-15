#include "gameviews.h"
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

#include"tower.h"
#include"monster.h"
gameviews::gameviews(QWidget *parent) : QMainWindow(parent)
{
<<<<<<< HEAD

    myblood=7;
    mymoney=100;

=======
    wave=3;
    myblood=7;
    mymoney=100;
    lose=0;
    win=0;
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa
  //回到主界面的按钮
    this->setFixedSize(2000,1500);
    buttons *backbu=new buttons(":/an.jpg");
    backbu->setParent(this);
    backbu->move(0,0);
    backbu->setFixedSize(60,60);
    connect(backbu,&buttons::clicked,this,[=](){
      emit back();
    });
    gettowerposition();
    addwaypoints();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updating()));
    timer->start(30);


<<<<<<< HEAD
}
void gameviews::paintEvent(QPaintEvent *){

    QPainter painter(this);


       QPixmap pixmap(":/map11.jpg");
       painter.drawPixmap(0,0,this->width(),this->height(),pixmap);//背景
=======
   buttons *set=new buttons(":/an.jpg");//按钮的图片
   set->setParent(this);
   set->move(800,800);//按钮的位置
   set->setFixedSize(400,400);//按钮的大
   connect(set,&buttons::clicked,this,&gameviews::addobject);

    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&gameviews::updating);
            timer->start(10);
    QTimer::singleShot(300, this, SLOT(start()));
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa


<<<<<<< HEAD
       foreach(const towerposition &towerpos, towerpositions)
           towerpos.draw(&painter);
=======
void gameviews::paintEvent(QPaintEvent *){

    QPainter painter(this);
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa

      foreach(tower *tower0,towers)
          tower0->draw(&painter);
      foreach(waypoint *wayp,waypoints)
          wayp->draw(&painter);

<<<<<<< HEAD
}
void gameviews::gettowerposition(){

        QPoint positions[] =
        {
            QPoint(0,150),
            QPoint(200,150),
            QPoint(400,150),
            QPoint(600,150),
            QPoint(800,150),
            QPoint(1000,150),
            QPoint(1180,420),
            QPoint(1180,620),
            QPoint(1180,250),

            QPoint(928, 430),

            QPoint(928,700),
            QPoint(100,465),
            QPoint(300,465),
            QPoint(500,465),
            QPoint(700,465),

            QPoint(700,665),

            QPoint(700,865),
             QPoint(1700,750),
             QPoint(1600,400),
             QPoint(1800,400),
            QPoint(1600,900),
        };
        int len	= sizeof(positions) / sizeof(positions[0]);

        for (int i = 0; i < len; ++i)
            towerpositions.push_back(positions[i]);
}

void gameviews::mouseEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    auto it = towerpositions.begin();
    while (it != towerpositions.end())
    {
        if (abletobuy() && it->containpoint(pressPos) && it->available())
        {
            it->setable();
            tower *tower_ = new tower(it->position(), this);
            towers.push_back(tower_);
            update();
            break;
        }
=======
       QPixmap pixmap(":/map11.jpg");
       painter.drawPixmap(0,0,this->width(),this->height(),pixmap);//背景

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
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa

        ++it;
    }
}
<<<<<<< HEAD
void gameviews::updating()
{
    foreach (monster *mon, monsters)
        mon->move();
    update();
}
=======
void gameviews::set_tower1(){
    tower *tower3=new tower(QPoint(500,600),":/red.jpg");//第一个塔的建立
     towers.push_back(tower3);
    update();
}
void gameviews::set_tower2(){
    tower *tower4=new tower(QPoint(1200,500),":/red.jpg");//第一个塔的建立
     towers.push_back(tower4);
    update();
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa

bool gameviews::abletobuy() const
{
    return true;
}
void gameviews::addwaypoints()
{
    waypoint *wayPoint1 = new waypoint(QPoint(0,350));
    waypoints.push_back(wayPoint1);

    waypoint *wayPoint2 = new waypoint(QPoint(850,350));
    waypoints.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);
    waypoint *wayPoint3 = new waypoint(QPoint(1080,350));
    waypoints.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);
    waypoint *wayPoint4 = new waypoint(QPoint(850,950));
    waypoints.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint2);
    waypoint *wayPoint5 = new waypoint(QPoint(1080,950));
    waypoints.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint3);

    waypoint *wayPoint9 = new waypoint(QPoint(1080,950));
    waypoints.push_back(wayPoint9);
    wayPoint9->setNextWayPoint(wayPoint4);


    waypoint *wayPoint10 = new waypoint(QPoint(1480,950));
    waypoints.push_back(wayPoint10);
    wayPoint10->setNextWayPoint(wayPoint9);
    waypoint *wayPoint11 = new waypoint(QPoint(1480,620));
    waypoints.push_back(wayPoint11);
    wayPoint11->setNextWayPoint(wayPoint10);
    waypoint *wayPoint12 = new waypoint(QPoint(2000,620));
    waypoints.push_back(wayPoint12);
    wayPoint12->setNextWayPoint(wayPoint11);


    waypoint *wayPoint6 = new waypoint(QPoint(1480,950));
    waypoints.push_back(wayPoint6);
    wayPoint6->setNextWayPoint(wayPoint5);
    waypoint *wayPoint7 = new waypoint(QPoint(1480,620));
    waypoints.push_back(wayPoint7);
    wayPoint7->setNextWayPoint(wayPoint6);
    waypoint *wayPoint8 = new waypoint(QPoint(2000,620));
    waypoints.push_back(wayPoint8);
    wayPoint8->setNextWayPoint(wayPoint7);

<<<<<<< HEAD

}
void gameviews::getdamage(int damage)
{
    // 暂时空实现，以后这里进行基地费血行为
}
void gameviews::remove(monster *mon)
{
    Q_ASSERT(mon);
    monsters.removeOne(mon);
    delete mon;
    if (monsters.empty())
    {
        ++_waves; // 当前波数加1
        // 继续读取下一波
        if (!loadwave())
        {
            // 当没有下一波时，这里表示游戏胜利
            // 设置游戏胜利标志为true
            _win = true;
            // 游戏胜利转到游戏胜利场景
            // 这里暂时以打印处理
        }
    }
}
bool gameviews::loadwave()
{
    if (_waves >= 6)
        return false;
    waypoint *startWayPoint = waypoints.back(); // 这里是个逆序的，尾部才是其实节点
    int enemyStartInterval[] = { 100, 500, 600, 1000, 3000, 6000 };
    for (int i = 0; i < 6; ++i)
    {
        monster *monster0 = new monster(startWayPoint, this);
        monsters.push_back(monster0);
        QTimer::singleShot(enemyStartInterval[i], monster0, SLOT(alive()));
    }
    return true;
}

=======
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


>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa
