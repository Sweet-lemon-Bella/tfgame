#include "tower.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
tower::tower(QPoint po ,QString  pixfile) : QObject(),_po(po),pix(pixfile){}

void tower::draw(QPainter *painter){
    painter->drawPixmap(_po,pix);
}
