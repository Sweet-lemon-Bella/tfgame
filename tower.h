#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QPixmap>
#include<QPainter>

#include<QTimer>

class gameviews;
class tower :public  QObject{
 Q_OBJECT
public:

    tower(QPoint pos, gameviews *control, const QPixmap &look=QPixmap("/:an.jpg"));
    void draw(QPainter *painter) const;
private:
    QPoint _position;
    int _range;
    int _power;
    int _rate;
    QPixmap _look;
     static const QSize _size;
     gameviews* _control;
signals:

private slots:


};

#endif // TOWER_H
