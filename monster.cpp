#include "monster.h"
#include "waypoint.h"
#include "tower.h"
#include "gameviews.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>

static const int Health_Bar_Width = 20;

const QSize monster::fixedsize(52, 52);

monster::monster(waypoint *start, gameviews *game, const QPixmap &sprite/* = QPixmap(":/image/enemy.png")*/)
    : QObject(0)
    , _alive(false)
    , _fullblood(40)
    , _blood(40)
    , _v(1.0)
    , _rotate(0.0)
    , _position(start->position())
    , _destinationwaypoint(start->nextWayPoint())
    , _control(game)
    , _look(sprite)
{
}

monster::~monster()
{
    attackedtowers.clear();
    _destinationwaypoint = NULL;
    _control = NULL;
}

void monster::alive()
{
    _alive = true;
}
 bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)
{
    const int xdif = point1.x() - point2.x();
    const int ydif = point1.y() - point2.y();
    const int distance = qSqrt(xdif * xdif + ydif * ydif);
    if (distance <= radius1 + radius2)
        return true;
    return false;
}

void monster::move()
{
    if (!_alive)
        return;

    if (collisionWithCircle(_position, 1, _destinationwaypoint->position(), 1))
    {
        // 敌人抵达了一个航点
        if (_destinationwaypoint->nextWayPoint())
        {
            // 还有下一个航点
            _position = _destinationwaypoint->position();
           _destinationwaypoint = _destinationwaypoint->nextWayPoint();
        }
        else
        {
            // 表示进入基地
            _control->getdamage(1);
            _control->remove(this);
            return;
        }
    }

    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = _destinationwaypoint->position();
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化
    qreal movementSpeed = _v;
    QVector2D normalized(targetPoint - _position);
    normalized.normalize();
    _position = _position + normalized.toPoint() * movementSpeed;

    // 确定敌人选择方向
    // 默认图片向左,需要修正180度转右
    _rotate = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 180;
}

void monster::draw(QPainter *painter) const
{
    if (!_alive)
        return;

    painter->save();

    QPoint healthBarPoint = _position + QPoint(-Health_Bar_Width / 2 - 5, -fixedsize.height() / 3);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);

    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)_blood/_fullblood * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);

    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-fixedsize.width() / 2, fixedsize.height() / 2);
    painter->translate(_position);
    painter->rotate(_rotate);
    // 绘制敌人
    painter->drawPixmap(offsetPoint, _look);

    painter->restore();
}

void monster::remove()
{
    if (attackedtowers.empty())
        return;

   // foreach (Tower *attacker, m_attackedTowersList)
  //      attacker->targetKilled();
    // 通知game,此敌人已经阵亡
    _control->remove(this);
}

void monster::getdamage(int damage)
{
   // _control->audioPlayer()->playSound(LaserShootSound);
    _blood -= damage;

    // 阵亡,需要移除
    if (_blood <= 0)
    {
        //m_game->audioPlayer()->playSound(EnemyDestorySound);
       // _control->awardGold(200);
        remove();
    }
}

void monster::attack(tower *attacker)
{
    attackedtowers.push_back(attacker);
}

// 表明敌人已经逃离了攻击范围
void monster::outofcircle(tower *attacker)
{
    attackedtowers.removeOne(attacker);
}

QPoint monster::pos() const
{
    return _position;
}

/* monster(waypoint *startWayPoint, gameviews *control, const QPixmap &look= QPixmap(":/image/enemy.png"));
    ~monster();

    void draw(QPainter *painter) const;
    void move();
    void getdamage(int damage);
    void remove();
    void attack(tower *attacker);
    void outofcircle(tower *attacker);
    QPoint pos() const;

public slots:
    void alive();

private:
    bool _alive;
    int	_fullblood;
    int	 _blood;
    double	_v;
    double _rotate;
    QPoint	_position;
    waypoint *		_destinationwaypoint;
    gameviews *	_control;
    QList<tower *>	attackedtowers;
    const QPixmap	_look;
    static const QSize fixedsize;*/
