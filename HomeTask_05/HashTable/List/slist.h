#pragma once
#include "list.h"
#include "listel.h"

class SingleList : public List
{
public:
    SingleList();
    ~SingleList();
    void add(QString  value);
    void remove(QString value);
    void printall();
    bool checkValue(QString value);
private:
    ListElement* head;
};


