#pragma once
#include <cstdlib>

class ListEl
{
public:
    ListEl(double value);
    ~ListEl();
    double getVal() const;
    void setVal(double value);
    void print();
    bool isEnding() const;
    ListEl* next;
protected:
    double val;
};


