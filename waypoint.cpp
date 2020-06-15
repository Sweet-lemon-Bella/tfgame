#include "waypoint.h"
#include <QPainter>
#include <QColor>

waypoint::waypoint(QPoint pos)
    : _position(pos), _nextwaypoint(NULL){}

void waypoint::setNextWayPoint(waypoint *nextPoint)
{
    _nextwaypoint = nextPoint;
}

waypoint* waypoint::nextWayPoint() const
{
    return _nextwaypoint;
}

const QPoint waypoint::position() const
{
    return _position;
}

void waypoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::black);
    painter->drawEllipse(_position, 6, 6);
    painter->drawEllipse(_position, 2, 2);

    if (_nextwaypoint)
        painter->drawLine(_position, _nextwaypoint->_position);
    painter->restore();
}
