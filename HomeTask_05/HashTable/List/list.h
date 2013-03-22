#pragma once
#include <QString>

class List
{
public:
    virtual void add(QString value) = 0;
    virtual void remove(QString value) = 0;
    virtual void printall() = 0;
    virtual bool checkValue(QString value) = 0;
    int getSize() const;
    bool isEmpty() const;
protected:
    int size;
    bool empty;
};

