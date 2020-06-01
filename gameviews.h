#ifndef GAMEVIEW1_H
#define GAMEVIEW1_H

#include <QMainWindow>
#include "tower.h"
#include <QList>

//gameviews类是打算建立成所有游戏界面的父类，然后派生界面123
class gameviews : public QMainWindow
{
    Q_OBJECT
public:
    explicit gameviews(QWidget *parent = nullptr);
    void set_tower();
    void paintEvent(QPaintEvent *event);
private:

    //绘制的塔
    QList<tower*>towers;
signals:
    void back();


public slots:
};

#endif // GAMEVIEW1_H
