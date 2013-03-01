#include "doublelistel.h"
#include <iostream>

DoubleListElement::DoubleListElement(int value)
{
    val = value;
    next = NULL;
    prev = NULL;
}

int DoubleListElement::getVal() const
{
    return val;
}

void DoubleListElement::setVal(int value)
{
    val = value;
}

DoubleListElement::~DoubleListElement()
{
    if (!isEnding())
        delete next;
}

void DoubleListElement::print()
{
    std::cout << val << '\t';
    if (!isEnding())
        next->print();
}

bool DoubleListElement::isEnding() const
{
    return next == NULL;
}
