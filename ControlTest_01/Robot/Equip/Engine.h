#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine(QObject* parent = 0) : QObject(parent), state(false), power(0) {}
signals:
    bool started();
    bool stopped();
    bool started(bool);
public slots:
    void start(int powerOfEngine)
    {
        state = true;
        power = powerOfEngine;
        emit started();
        emit started(true);
    }

    void stop()
    {
        state = false;
        power = 0;
        emit stopped();
        emit started(false);
    }

private:
    bool state;
    int power;
};

#endif // ENGINE_H
