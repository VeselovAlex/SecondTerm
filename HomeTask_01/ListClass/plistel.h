#pragma once

class PListEl
{
public:
    PListEl(int val);
    ~PListEl();
    int getValue();
    bool isEnding();
private:
    int value;
    PListEl* next;
};


