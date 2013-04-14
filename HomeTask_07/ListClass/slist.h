#pragma once
#include "list.h"
#include "listel.h"

class SingleList : public List
{
public:
    SingleList();
    ~SingleList();
    void add(int value) throw (DataExistsException);
    void remove(int value) throw (EmptyContainerException, DataNotFoundException);
    void printall();
    ListElement* getHeadPointer();
private:
    ListElement* head;
};


