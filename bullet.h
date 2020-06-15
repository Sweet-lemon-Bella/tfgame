#ifndef BULLET_H
#define BULLET_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include<QPainter>
#include"enemy.h"
#include"objectx.h"
class gameviews;
class bullet : public objectx{
 Q_OBJECT
     Q_PROPERTY(QPoint currentPos  READ getCurrentPos WRITE setCurrentPos)
public:
    bullet(QPoint start, QPoint targetp,QString file, int damage, enemy *target);
    void draw(QPainter *painter) ;
    void move();
    void hit();
private slots:
private:
    enemy *	  target;
    int	      damage;
    static const QSize fixedSize;
gameviews * logic;
};

#endif // BULLET_H
