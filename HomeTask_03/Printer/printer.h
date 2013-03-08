#ifndef PRINTER_H
#define PRINTER_H
#include <string>

class Printer
{
public:
    Printer(){}
    virtual ~Printer(){}
    virtual void print(std::string toPrint) = 0;
};

#endif // PRINTER_H
