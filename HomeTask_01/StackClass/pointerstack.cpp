#include "pointerstack.h"

PointerStack::PointerStack()
{
    top = NULL;
}

PointerStack::~PointerStack()
{
    while (!isEmpty())
        pop();
}

void PointerStack::push(double val)
{
    ListEl* tmp = new ListEl(val);
    tmp->next = top;
    top = tmp;
    size++;
    empty = false;
}

double PointerStack::pop()
{
    if(isEmpty())
        return 0;

    double result = top->getVal();
    ListEl* tmp = top;
    top = tmp->next;
    tmp->next = NULL;
    delete tmp;
    size--;
    if (size <= 0)
        empty = true;
    return result;
}

double PointerStack::peek() const
{
    return top->getVal();
}
