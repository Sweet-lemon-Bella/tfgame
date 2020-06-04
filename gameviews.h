#ifndef GAMEVIEW1_H
#define GAMEVIEW1_H

#include <QMainWindow>
#include <QList>
#include"buttons.h"
class bullet;
class tower;
class enemy;
class objectx;

class gameviews : public QMainWindow
{
    Q_OBJECT
public:
    explicit gameviews(QWidget *parent = nullptr);
    void set_tower0();//建塔的槽函数
    void set_tower1();
    void set_tower2();

    void paintEvent(QPaintEvent *event);
    void addobject();
    void updating();

    void attack();

    void removedenemy(enemy *enemy);
    void getHpDamage(int damage = 1);

    void removedbullet(bullet *bullet);
    void addbullet(bullet *bullet);
    void getmoney(int money);
     QList<enemy*>enemys;
private:
    int	  wave;
    int	  myblood;
    int	  mymoney;
    bool lose;
    bool	win;
    //将tower放到list里面
    QList<tower*>towers;

    QList<objectx*>object_list;
    QList<bullet*>bullets;

signals:
    void back();


public slots:
    void start();
};

#endif // GAMEVIEW1_H
