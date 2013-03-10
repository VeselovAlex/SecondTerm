#ifndef PRINTER_H
#define PRINTER_H
#include <string>
/**
 * @brief The Abstract Printer class
 */
class Printer
{
public:
    virtual ~Printer(){}
    /**
     * @brief print prints string
     * @param toPrint String to print
     */
    virtual void print(std::string toPrint) = 0;
};

#endif // PRINTER_H
