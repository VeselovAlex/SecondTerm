#pragma once
#include <QString>
#include <cstdlib>

class ListElement
{
public:
    ListElement(QString value);
    ~ListElement();
    QString getVal() const;
    void setVal(QString value);
    void print();
    bool isEnding() const;
    ListElement* next;
protected:
    QString val;
};


