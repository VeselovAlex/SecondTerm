#pragma once
#include "Exceptions/dataexistsexception.h"
#include "Exceptions/datanotfoundexception.h"
#include "Exceptions/emptycontainerexception.h"

class List
{
public:
    virtual void add(int value) throw (DataExistsException) = 0;
    virtual void remove(int value) throw (EmptyContainerException, DataNotFoundException) = 0;
    virtual void printall() = 0;
    int getSize() const;
    bool isEmpty() const;
protected:
    int size;
    bool empty;
};

