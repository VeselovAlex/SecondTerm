#include "listbox.h"
#include <iostream>

ListBox::ListBox(int value)
{
    val = value;
    next = NULL;
}

ListBox::~ListBox()
{
    if (!isEnding())
        delete next;
}


int ListBox::getVal() const
{
    return val;
}

void ListBox::setVal(int value)
{
    val = value;
}

void ListBox::print()
{
    std::cout << val << '\t';
    if (!isEnding())
        next->print();
}

bool ListBox::isEnding() const
{
    return next == NULL;
}
