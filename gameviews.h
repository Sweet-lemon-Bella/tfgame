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
<<<<<<< HEAD
=======
    void updating();

    void attack();

    void removedenemy(enemy *enemy);
    void getHpDamage(int damage = 1);
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa

    bool loadwave() ;
    void attack();
    void mouseEvent(QMouseEvent *event);
    void getdamage(int damage);
     void remove(monster *mon);
private:

    int	  myblood;
    int	  mymoney;
<<<<<<< HEAD
    int    _waves;
=======
    bool lose;
    bool	win;
    //将tower放到list里面
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa
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
<<<<<<< HEAD
    void updating();
=======
    void start();
>>>>>>> b77da3ef0e027934876167a9554754d160ec11fa
};

#endif // GAMEVIEW1_H
