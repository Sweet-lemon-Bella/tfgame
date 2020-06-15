#ifndef SOUND_H
#define SOUND_H

#include <QObject>

class sound : public QObject
{
    Q_OBJECT
public:
    explicit sound(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SOUND_H