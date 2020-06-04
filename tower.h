#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QPixmap>
#include<QPainter>
#include "objectx.h"
#include"enemy.h"
#include<QTimer>

class gameviews;
class tower :public  QObject{
 Q_OBJECT
public:
    tower(QPoint po ,QString  pixfile);
    void draw(QPainter *painter);
    void checkEnemyInRange();
    void targetKilled();
    void attackEnemy();
    void chooseEnemyForAttack(enemy *enemy1);
    void removeBullet();
    void damageEnemy();
    void lostSightOfEnemy();
     bool haveMonsterCode(int code);

private:
    gameviews * logic;
    QPoint	po;
    QPixmap	pix;
    bool	attacking;
    int		attackRange;
    int		damage;
    int		Rate;
    enemy *	chosenenemy;
    QTimer *timer;

signals:

private slots:
    void shootWeapon();

};

#endif // TOWER_H
