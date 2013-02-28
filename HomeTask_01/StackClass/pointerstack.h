#pragma once
#include "stack.h"
#include "listel.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(double val);
    double pop();
    double peek() const;
private:
    ListElement* top;
};

