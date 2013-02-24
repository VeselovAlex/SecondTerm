#include "listel.h"
#include <iostream>

ListEl::ListEl(int value)
{
    val = value;
    next = NULL;
}

ListEl::~ListEl()
{
    if (!isEnding())
        delete next;
}


int ListEl::getVal() const
{
    return val;
}

void ListEl::setVal(int value)
{
    val = value;
}

void ListEl::print()
{
    std::cout << val << '\t';
    if (!isEnding())
        next->print();
}

bool ListEl::isEnding() const
{
    return next == NULL;
}
