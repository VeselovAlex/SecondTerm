#include "arraystack.h"

ArrayStack::ArrayStack(int max)
{
    maxSize = max;
    stackArray = new double[max];
    top = 0;
    free = 0;
}

ArrayStack::~ArrayStack()
{
    if (!isEmpty())
        delete[] stackArray;
}

void ArrayStack::push(double val)
{
    if (size >= maxSize)
        return;
    stackArray[free] = val;
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
    return stackArray[free];
}

double ArrayStack::peek() const
{
    return stackArray[top];
}
