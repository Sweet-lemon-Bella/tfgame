#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include <QPoint>
#include <QSize>
#include <QPixmap>


class towerposition
{
public:
    towerposition(QPoint position,const QPixmap &look=QPixmap(":/xiong.png"));
    void setavailable(bool _available=0);
    bool available() const;
    bool containpoint(const QPoint &position)const;
    void draw(QPainter *painter) const;
private:
    QPoint _position;
    bool _available;
    QPixmap _look;
    static const QSize _size;
};

#endif // TOWERPOSITION_H
