#ifndef RESOURCECLASS_H
#define RESOURCECLASS_H

#include <iostream>

class ResourceClass
{
public:
    ResourceClass()
    {
        std::clog << "Resource class created\n";

    }

    ~ResourceClass()
    {
        std::clog << "Resource class deleted\n";
    }
};

#endif // RESOURCECLASS_H
