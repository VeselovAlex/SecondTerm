#pragma once

class Stack
{
public:
    Stack();
    virtual void push(double val) = 0;
    virtual double pop() = 0;
    virtual double peek() const = 0;
    bool isEmpty() const;
    int getSize() const;
protected:
    int size;
    bool empty;
};

