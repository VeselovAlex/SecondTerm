#include "listel.h"
#include <iostream>

ListEl::ListEl(double value)
{
    val = value;
    next = NULL;
}

ListEl::~ListEl()
{
    if (!isEnding())
        delete next;
}


double ListEl::getVal() const
{
    return val;
}

void ListEl::setVal(double value)
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
