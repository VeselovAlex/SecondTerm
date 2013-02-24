#pragma once
#include <cstdlib>

class ListEl
{
public:
    ListEl(int value);
    ~ListEl();
    int getVal() const;
    void setVal(int value);
    void print();
    bool isEnding() const;
    ListEl* next;
protected:
    int val;
};


