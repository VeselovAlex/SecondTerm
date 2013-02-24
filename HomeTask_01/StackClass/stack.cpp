#include "stack.h"

Stack::Stack()
{
    empty = true;
    size = 0;
}

bool Stack::isEmpty() const
{
    return empty;
}

int Stack::getSize() const
{
    return size;
}
