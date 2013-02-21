#include "plistel.h"

PListEl::PListEl(int val)
{
    value = val;
    next = nullptr;
}

PListEl::~PListEl()
{
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

