#pragma once
#include "list.h"
#include "listbox.h"

class SList : public List
{
public:
    SList();
    ~SList();
    void add(int value);
    void remove(int value);
    void printall();
private:
    ListBox* head;
};


