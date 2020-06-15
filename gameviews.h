#ifndef GAMEVIEW1_H
#define GAMEVIEW1_H

#include <QMainWindow>
#include <QList>
#include"buttons.h"
#include"towerposition.h"
#include"waypoint.h"
#include"monster.h"


class gameviews : public QMainWindow
{
    Q_OBJECT
public:
    explicit gameviews(QWidget *parent = nullptr);
    bool abletobuy() const;
    void paintEvent(QPaintEvent *event);
    void addobject();

    bool loadwave() ;
    void attack();
    void mouseEvent(QMouseEvent *event);
    void getdamage(int damage);
     void remove(monster *mon);
private:

    int	  myblood;
    int	  mymoney;
    int    _waves;
    QList<tower*>towers;
    QList<monster*>monsters;
    QList<towerposition> towerpositions;
    bool   _win;
   // QList<bullet*>bullets;
    void gettowerposition();
    QList<waypoint *> waypoints;
    void addwaypoints();

signals:
    void back();

public slots:
    void updating();
};

#endif // GAMEVIEW1_H
