#include "tower.h"
#include"gameviews.h"
const QSize tower::_size(50,50);
tower::tower(QPoint pos, gameviews *control, const QPixmap &look):_range(70),_power(10),_rate(1000){
    _look=look;
    _position=pos;
    _control=control;
}
void tower::draw(QPainter *painter) const{
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_position, _range, _range);
    painter->drawPixmap(_position,_look);
    painter->restore();

<<<<<<< HEAD
=======

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
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa
}
