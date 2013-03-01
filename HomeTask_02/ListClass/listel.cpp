#include "listel.h"
#include <iostream>

ListElement::ListElement(int value)
{
    val = value;
    next = NULL;
}

ListElement::~ListElement()
{
    delete next;
}


int ListElement::getVal() const
{
    return val;
}

void ListElement::setVal(int value)
{
    val = value;
}

void ListElement::print()
{
    std::cout << val << '\t';
    if (!isEnding())
        next->print();
}

bool ListElement::isEnding() const
{
    return next == NULL;
}
