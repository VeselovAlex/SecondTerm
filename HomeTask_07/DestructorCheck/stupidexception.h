#ifndef STUPIDEXCEPTION_H
#define STUPIDEXCEPTION_H
#include <iostream>
class StupidException
{
public:
    StupidException()
    {
        std::clog << "Studid exception thrown\n";
    }

};

#endif // STUPIDEXCEPTION_H
