#include "buttons.h"
#include<QPixmap>
#include "gameviews.h"

//自己建立的按钮类
buttons::buttons(QString pi):QPushButton ()
{
    QPixmap pixmap(pi);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));


}
