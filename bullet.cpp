#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>
#include "gameviews.h"

bullet::bullet(QPoint start, QPoint targetp,QString file, int damage, enemy *target):objectx(start,targetp,file){
    this->damage=damage;
    this->target=target;
}
const QSize fixedSize(10,10);
void bullet::move()
{
    static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "currentPos");
    animation->setDuration(duration);
    animation->setStartValue(startPos);
    animation->setEndValue(targetPos);
    connect(animation, SIGNAL(finished()), this, SLOT(hit()));
    animation->start();
}

void bullet::hit()
{
    if (logic->enemys.indexOf(target) != -1)
        target->getdamage(damage);

}
void bullet::draw(QPainter *painter)
{
    painter->drawPixmap(currentPos,pixmap);
}
