#include "Processor.h"

Processor::Processor(QObject *parent)
{
    engines->push_back(new Engine(this));

    distanceSensors->push_back(new DistanceSensor(this));
    touchSensors->push_back(new DistanceSensor(this));
}

void Processor::command(Command *currCommand)
{
    switch (currCommand->commandText()) {
    case "ENGSTART":
    {
        connect(this, SIGNAL(engineStart(int)), engines[currCommand->parameter()], SLOT(start(int)));
        emit engineStart(currCommand->parameter());
        disconnect(this, SIGNAL(engineStart(int)), engines[currCommand->parameter()], SLOT(start(int)));
        break;
    }
    case "ENGSTOP":
    {
        connect(this, SIGNAL(engineStop()), engines[currCommand->parameter()], SLOT(stop()));
        emit engineStop();
        disconnect(this, SIGNAL(engineStop()), engines[currCommand->parameter()], SLOT(stop()));
        break;
    }
    case "DISTDATA":
    {
        connect(this, SIGNAL(getDistance()), distanceSensors[currCommand->parameter()], SLOT(scanDistance()));
        emit getDistance();
        disconnect(this, SIGNAL(getDistance()), distanceSensors[currCommand->parameter()], SLOT(scanDistance()));
        break;
    }
    case "TOUCHDATA":
    {
        connect(this, SIGNAL(getTouchData()), touchSensors[currCommand->parameter()], SLOT(sendTouchPosition()));
        emit engineStop();
        disconnect(this, SIGNAL(getTouchData()), touchSensors[currCommand->parameter()], SLOT(sendTouchPosition()));
        break;
    }
    default:
        break;
    }
}



