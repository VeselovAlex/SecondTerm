#include "plistel.h"

PListEl::PListEl(int val)
{
    value = val;
    next = nullptr;
}

PListEl::~PListEl()
{
    if (!isEnding())
        delete next;
}

int PListEl::getValue()
{
    return value;
}

bool PListEl::isEnding()
{
    return next == nullptr;
}

void PListEl::print()
{
    std::cout << value << '\t';
    if (!isEnding())
        next.print();
}

