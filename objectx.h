#ifndef OBJECTX_H
#define OBJECTX_H

#include <QObject>

class objectx : public QObject
{
    Q_OBJECT
public:
    explicit objectx(QObject *parent = nullptr);

signals:

public slots:
};

#endif // OBJECTX_H