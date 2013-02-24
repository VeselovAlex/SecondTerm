#pragma once
#include "list.h"
#include "listel.h"

class SingleList : public List
{
public:
    SingleList();
    ~SingleList();
    void add(int value);
    void remove(int value);
    void printall();
private:
    ListEl* head;
};


