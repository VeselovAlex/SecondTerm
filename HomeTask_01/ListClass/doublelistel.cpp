#include "doublelistel.h"
#include <iostream>

DoubleListEl::DoubleListEl(int value)
{
    val = value;
    next = NULL;
    prev = NULL;
}

int DoubleListEl::getVal() const
{
    return val;
}

void DoubleListEl::setVal(int value)
{
    val = value;
}

DoubleListEl::~DoubleListEl()
{
    if (!isEnding())
        delete next;
}

void DoubleListEl::print()
{
    std::cout << val << '\t';
    if (!isEnding())
        next->print();
}

bool DoubleListEl::isEnding() const
{
    return next == NULL;
}
