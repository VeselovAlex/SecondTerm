#pragma once

class DoubleListElement
{
public:
    DoubleListElement(int value);
    ~DoubleListElement();
    int getVal() const;
    void setVal(int value);
    void print();
    bool isEnding() const;
    DoubleListElement* next;
    DoubleListElement* prev;
protected:
    int val;
};

