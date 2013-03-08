#ifndef CONSOLEPRINTER_H
#define CONSOLEPRINTER_H
#include "printer.h"
#include <iostream>

class ConsolePrinter : public Printer
{
public:
    ConsolePrinter(){}
    ~ConsolePrinter(){}
    void print(std::string toPrint);
};

#endif // CONSOLEPRINTER_H
