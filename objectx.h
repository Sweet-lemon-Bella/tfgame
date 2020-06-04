#ifndef OBJECTX_H
#define OBJECTX_H

#include <QObject>
#include <QObject>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QPainter>
class objectx : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentPos  READ getCurrentPos WRITE setCurrentPos)
public:
   objectx(QPoint startPos,QPoint  targetPos,QString filename);
   void draw(QPainter *painter);
   void move();
   QPoint getCurrentPos();
   void setCurrentPos(QPoint pos);

protected:
   QPoint  startPos;
   QPoint targetPos;
   QPoint currentPos;
   QPixmap pixmap;
signals:

public slots:
};

#endif // OBJECTX_H
