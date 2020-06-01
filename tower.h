#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
class tower : public QObject
{
    Q_OBJECT
public:
    tower(QPoint po ,QString  pixfile);
    void draw( QPainter *painter);
private:
     QPoint _po;
     QPixmap pix;
signals:

public slots:
};

#endif // TOWER_H
