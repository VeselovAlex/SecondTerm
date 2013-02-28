#pragma once
#include <cstdlib>

class ListElement
{
public:
    ListElement(double value);
    ~ListElement();
    double getVal() const;
    void setVal(double value);
    void print();
    bool isEnding() const;
    ListElement* next;
protected:
    double val;
};


