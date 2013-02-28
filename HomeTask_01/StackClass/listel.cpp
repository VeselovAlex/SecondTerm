#include "listel.h"
#include <iostream>

ListElement::ListElement(double value)
{
    val = value;
    next = NULL;
}

ListElement::~ListElement()
{
    delete next;
}


double ListElement::getVal() const
{
    return val;
}

void ListElement::setVal(double value)
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


