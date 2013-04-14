#pragma once
#include "doublelistel.h"
#include "list.h"

class DoubleList : public List
{
public:
    DoubleList();
    ~DoubleList();
    void add(int value) throw (DataExistsException);
    void remove(int value) throw (EmptyContainerException, DataNotFoundException);
    void printall();
    DoubleListElement* getHeadPointer();
private:
    DoubleListElement* head;
};

