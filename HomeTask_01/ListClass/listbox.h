#pragma once
#include <cstdlib>


class ListBox
{
public:
    ListBox(int value);
    ~ListBox();
    int getVal() const;
    void setVal(int value);
    void print();
    bool isEnding() const;
    ListBox* next;
private:
    int val;
};


