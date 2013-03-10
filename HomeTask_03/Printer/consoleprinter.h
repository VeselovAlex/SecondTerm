#ifndef CONSOLEPRINTER_H
#define CONSOLEPRINTER_H
#include "printer.h"
#include <iostream>

/**
 * @brief The Console Printer class
 */
class ConsolePrinter : public Printer
{
public:
    /**
     * @brief print prints string to console
     * @param toPrint String to print
     */
    void print(std::string toPrint);
};

#endif // CONSOLEPRINTER_H
