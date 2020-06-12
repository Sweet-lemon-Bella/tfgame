#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include<QPoint>
#include<QList>
#include"objectx.h"
#include<QObject>

class tower;
class gameviews;

//敌人类
class enemy:public objectx
{
 Q_OBJECT
 Q_PROPERTY(QPoint currentPos  READ getCurrentPos WRITE setCurrentPos)
public:
    enemy(QPoint m ,QPoint n,QString pic);  //构造
    int getblood() const;  //获取生命值
    void setblood(int b);    //设置生命值
    void getdamage(int damage);
    void getRemoved();

    void draw(QPainter *painter);
    void getAttacked(tower *tower0);
    void gotLostSight(tower *tower0);

private:
   gameviews * logic;
    QString pic;             //怪物图片路径
    int blood;                  //怪物生命值
    int speed = 10;       //怪物移动速
    QList<tower*>attacktowers;
    bool live;
public slots:
     void run();
};

#endif // MONSTER_H
