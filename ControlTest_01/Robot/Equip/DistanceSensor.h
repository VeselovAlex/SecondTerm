#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <QObject>

class DistanceSensor : public QObject
{
    Q_OBJECT
public:
    explicit DistanceSensor(QObject *parent = 0) : QObject(parent), currDistance(0) {}
    
signals:
    bool distance(double);
    bool available(bool);
public slots:
    void scanDistance()
    {
        /*Scanning*/
        currDistance = rand();
        emit distance(currDistance);
    }

private:
    double currDistance;
    
};

#endif // DISTANCESENSOR_H
