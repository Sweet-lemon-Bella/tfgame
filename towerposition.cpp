#include "towerposition.h"
#include <QPainter>

const QSize towerposition::_size(500,500);
towerposition::towerposition(QPoint position,const QPixmap &look):_position(position),_available(1),_look(look){}

bool towerposition::containpoint(const QPoint &position) const{
    bool x_in = _position.x() < position.x() && position.x() < (_position.x() + _size.width());
    bool y_in = _position.y() < position.y() && position.y() < (_position.y() + _size.height());
    return x_in && y_in;
}

bool towerposition::available() const
{
    return _available;
}

void towerposition::setavailable(bool available){
    _available=available;
}

void towerposition::draw(QPainter *painter) const
{
    painter->drawPixmap(_position.x(), _position.y(),20,20, _look);
}
