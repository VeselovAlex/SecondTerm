#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(int max);
    ~ArrayStack();
    void push(double val);
    double pop();
    double peek() const;
private:
    int maxSize;
    double *stackarr;
    int top;
    int free;
};

