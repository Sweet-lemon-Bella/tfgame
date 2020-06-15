#include "tower.h"
#include"gameviews.h"
const QSize tower::_size(50,50);
tower::tower(QPoint pos, gameviews *control, const QPixmap &look):_range(70),_power(10),_rate(1000){
    _look=look;
    _position=pos;
    _control=control;
}
void tower::draw(QPainter *painter) const{
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_position, _range, _range);
    painter->drawPixmap(_position,_look);
    painter->restore();

}
