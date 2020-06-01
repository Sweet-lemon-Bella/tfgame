#include "gameviews.h"
#include "buttons.h"
#include<QPainter>
gameviews::gameviews(QWidget *parent) : QMainWindow(parent)
{

  //回到主界面的按钮
    this->setFixedSize(2000,1500);
    buttons *backbu=new buttons(":/an.jpg");
    backbu->setParent(this);
    backbu->move(0,0);
   connect(backbu,&buttons::clicked,this,[=](){
      emit back();
    });

//建塔
   buttons *set_tower=new buttons(":/an.jpg");
   set_tower->setParent(this);
   set_tower->move(300,500);

   connect(set_tower,&buttons::clicked,this,&gameviews::set_tower);


}

void gameviews::paintEvent(QPaintEvent *){
    QPainter painter(this);
//第一场景的界面绘制
    QPixmap pixmap(":/map11.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

    foreach(tower *tower2,towers)
        tower2->draw(&painter);
}


//建塔
void gameviews::set_tower(){
    tower *tower1=new tower(QPoint(1500,1000),":/yellow.jpg");
    towers.push_back(tower1);
    update();
}
