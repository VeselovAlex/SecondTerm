#pragma once

class List
{
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void printall() = 0;
    int getSize() const;
    bool isEmpty() const;
protected:
    int size;
    bool empty;
};

