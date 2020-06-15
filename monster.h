#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include "waypoint.h"
#include "tower.h"
#include <QPainter>
#include <QPixmap>
class gameviews;
class monster : public QObject
{
    Q_OBJECT
public:
    monster(waypoint *startWayPoint, gameviews *control, const QPixmap &look= QPixmap(":/po.png"));
    ~monster();

    void draw(QPainter *painter) const;
    void move();
    void getdamage(int damage);
    void remove();
    void attack(tower *attacker);
    void outofcircle(tower *attacker);
    QPoint pos() const;
   friend bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2);
public slots:
    void alive();

private:
    bool _alive;
    int	_fullblood;
    int	 _blood;
    double	_v;
    double _rotate;
    QPoint	_position;
    waypoint *		_destinationwaypoint;
    gameviews *	_control;
    QList<tower *>	attackedtowers;
    const QPixmap	_look;
    static const QSize fixedsize;
};

#endif // MONSTER_H
