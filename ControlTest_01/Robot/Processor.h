#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>
#include <QSignalMapper>
#include "Equip/Engine.h"
#include "Equip/DistanceSensor.h"
#include "Equip/TouchSensor.h"
#include "Command.h"


class Processor : public QObject
{
    Q_OBJECT
public:
    explicit Processor(QObject *parent = 0);
    
signals:
    bool engineStart(int power);
    bool engineStop();

    bool getDistance();
    bool getTouchData();
    
public slots:
    void command(Command *currCommand);

private:
    QList<Engine*>* engines;
    QList<DistanceSensor*>* distanceSensors;
    QList<TouchSensor*>* touchSensors;
    
};

#endif // PROCESSOR_H
