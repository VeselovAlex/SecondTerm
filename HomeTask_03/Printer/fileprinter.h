#ifndef FILEPRINTER_H
#define FILEPRINTER_H
#include "printer.h"
#include <iostream>
#include <fstream>

/**
 * @brief The File Printer class
 */
class FilePrinter : public Printer
{
public:
    /**
     * @brief FilePrinter constructor
     * @param file Path to output file
     */
    FilePrinter(const char *file) : filename(file){}
    /**
     * @brief print prints string to file
     * @param toPrint String to print
     */
    void print(std::string toPrint);
private:
    const char *filename;
};

#endif // FILEPRINTER_H
