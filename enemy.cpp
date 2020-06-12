#include "enemy.h"
#include <QDebug>
#include "gameviews.h"
#include<QPainter>

//怪物类函数实现
enemy::enemy(QPoint m,QPoint n, QString pic): objectx(m,n,pic){

    blood=100;
}

int enemy::getblood() const{
    return blood;
}//血量
void enemy::setblood(int b){
    blood=b;
}

void enemy::getAttacked(tower *tower0)
{
    attacktowers.push_back(tower0);
}
//被攻击

void enemy::gotLostSight(tower *tower0)
{
    attacktowers.removeOne(tower0);
}//在攻击范围之外

void enemy::getdamage(int damage)
{

    blood -= damage;


    if (blood <= 0)
    {

        logic->getmoney(200);
    }
}
void enemy::draw(QPainter *painter){

    painter->drawPixmap(currentPos,pic);
}
void enemy::run()
{
    move();
}
