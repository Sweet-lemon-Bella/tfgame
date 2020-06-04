#include "objectx.h"

objectx::objectx(QPoint startPos,QPoint  targetPos,QString filename):QObject(),pixmap(filename){
    this->currentPos=startPos;
    this->startPos=startPos;
    this->targetPos=targetPos;
}


void objectx::draw(QPainter *painter){
    painter->drawPixmap(currentPos,pixmap);
}

//画图
void objectx::move(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"currentPos");
    animation->setDuration(2000);
    animation->setStartValue(startPos);

    animation->setEndValue(targetPos);
    animation->start();
}

//移动
QPoint objectx::getCurrentPos(){
    return this->currentPos;
}
void objectx::setCurrentPos(QPoint pos){
    this->currentPos=pos;
}
