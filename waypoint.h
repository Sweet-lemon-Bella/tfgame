#ifndef WAYPOINT_H
#define WAYPOINT_H

#include<QPoint>
#include<QPainter>
class waypoint
{
public:
    waypoint(QPoint pos);
    void setNextWayPoint(waypoint *nextPoint);
    waypoint* nextWayPoint() const;
    const QPoint position() const;
    void  draw(QPainter *painter) const;

private:

    const QPoint _position;
    waypoint *_nextwaypoint;
};

#endif // WAYPOINT_H
