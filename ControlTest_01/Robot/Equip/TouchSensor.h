#ifndef TOUCHSENSOR_H
#define TOUCHSENSOR_H

#include <QObject>

class TouchSensor : public QObject
{
    Q_OBJECT
public:
    explicit TouchSensor(QObject *parent = 0) : QObject(parent), currDistance(0) {}

signals:
    bool touch();
    bool touch(double x, double y);
    bool available(bool);
public slots:
    void sendTouchPosition()
    {
        /*Scanning*/
        xCoordinate = rand();
        yCoordinate = rand();
        emit touch();
        emit touch(xCoordinate, yCoordinate);
    }

private:
    double xCoordinate;
    double yCoordinate;
};

#endif // TOUCHSENSOR_H
