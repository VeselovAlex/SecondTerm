#pragma once
#include <iostream>
class PListEl
{
public:
    PListEl(int val);
    ~PListEl();
    int getValue();
    void print();
    bool isEnding();
private:
    int value;
    PListEl next;
};


