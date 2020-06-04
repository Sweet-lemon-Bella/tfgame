#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include<QPoint>
#include<QList>
#include"objectx.h"

class tower;
class gameviews;

//敌人类
class enemy:public objectx
{

public:
    enemy(QPoint m, QString pic);  //构造
    QPoint getpoint();
    int getblood() const;  //获取生命值
    void setblood(int b);    //设置生命值
    void getdamage(int damage);
    void getRemoved();
    void getAttacked(tower *tower0);
    void gotLostSight(tower *tower0);

private:
   gameviews * logic;
    QPoint n;                //怪物坐标
    QString pic;             //怪物图片路径
    int blood;                  //怪物生命值
    int speed = 10;       //怪物移动速
    QList<tower*>attacktowers;

};

#endif // MONSTER_H
