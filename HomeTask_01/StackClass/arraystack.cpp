#include "arraystack.h"

ArrayStack::ArrayStack(int max)
{
    maxSize = max;
    stackarr = new double[max];
    top = 0;
    free = 0;
}

ArrayStack::~ArrayStack()
{
    if (!isEmpty())
        delete[] stackarr;
}

void ArrayStack::push(double val)
{
    if (size >= maxSize)
        return;
    stackarr[free] = val;
    top = free;
    free++;
    size++;
    empty = false;
}

double ArrayStack::pop()
{
    if (isEmpty())
        return 0;
    top--;
    free--;
    size--;
    if (size <= 0)
        empty = true;
    return stackarr[free];
}

double ArrayStack::peek() const
{
    return stackarr[top];
}
