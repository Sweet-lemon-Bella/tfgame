#include "enemy.h"
#include <QDebug>
#include "gameviews.h"

//怪物类函数实现
enemy::enemy(QPoint m, QString pic): objectx(QPoint(0,0),QPoint(0,0),pic){
    n=m;
    blood=100;
}

int enemy::getblood() const{
    return blood;
}//血量
void enemy::setblood(int b){
    b=blood;
}
QPoint enemy::getpoint(){
    return n;
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
