#pragma once
#include <list.h>
#include <plistel.h>

class PList : public List
{
public:
    PList();
    ~PList();
    void add(int value);
    void remove(int value);
    void printall();
protected:
    PListEl head;
};

