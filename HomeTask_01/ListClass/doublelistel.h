#pragma once

class DoubleListEl
{
public:
    DoubleListEl(int value);
    ~DoubleListEl();
    int getVal() const;
    void setVal(int value);
    void print();
    bool isEnding() const;
    DoubleListEl* next;
    DoubleListEl* prev;
protected:
    int val;
};

