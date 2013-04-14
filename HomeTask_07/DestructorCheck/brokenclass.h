#ifndef BROKENCLASS_H
#define BROKENCLASS_H

#include "resourceclass.h"
#include "stupidexception.h"

class BrokenClass
{
public:
    BrokenClass() throw (StupidException)
    {
        std::clog << "Brocken class created\n";
        throw StupidException();
    }

    ~BrokenClass()
    {
        std::clog << "Brocken class deleted\n";
    }

private:
    ResourceClass data;
};

#endif // BROKENCLASS_H
