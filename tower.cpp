#include "tower.h"
#include"enemy.h"
#include"bullet.h"
#include"gameviews.h"
tower::tower(QPoint po ,QString  pixfile) :QObject(),po(po),pix(pixfile),
   attacking(false)
       ,attackRange(70)
       , damage(10)
       , Rate(1000)
       , chosenenemy(){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(shootWeapon()));
}


void tower::attackEnemy()
{
    // 启动攻击模式
   timer->start(Rate);
}
void tower::chooseEnemyForAttack(enemy *enemy1)
{
    chosenenemy = enemy1;
    attackEnemy();
    chosenenemy ->getAttacked(this);
}
//选择攻击的敌人

void tower::shootWeapon()
{
    bullet *bullet1 = new bullet(po, chosenenemy->getCurrentPos(),":/an.jpg", damage, chosenenemy);
    bullet1->move();
    logic->addbullet(bullet1);
}
//塔的攻击

void tower::draw(QPainter *painter){
    painter->drawPixmap(po,pix);
}

void tower::lostSightOfEnemy()
{
    chosenenemy->gotLostSight(this);
    if (chosenenemy)
       chosenenemy=0;
    timer->stop();
}
//不在攻击范围内的敌人
