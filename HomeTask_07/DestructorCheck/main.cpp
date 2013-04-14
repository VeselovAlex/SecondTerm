#include "brokenclass.h"


int main()
{
    try
    {
        BrokenClass failure;
    }
    catch (StupidException)
    {
        std::clog << "Stupid exception caught\n";
    }
    return 0;
}

