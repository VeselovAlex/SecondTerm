#pragma once
#include <cstdlib>

class ListElement
{
public:
    ListElement(int value);
    ~ListElement();
    int getVal() const;
    void setVal(int value);
    void print();
    bool isEnding() const;
    ListElement* next;
protected:
    int val;
};


