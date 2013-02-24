#pragma once
#include "doublelistel.h"
#include "list.h"

class DoubleList : public List
{
public:
    DoubleList();
    ~DoubleList();
    void add(int value);
    void remove(int value);
    void printall();
private:
    DoubleListEl* head;
};

