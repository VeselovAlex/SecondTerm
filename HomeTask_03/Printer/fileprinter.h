#ifndef FILEPRINTER_H
#define FILEPRINTER_H
#include "printer.h"
#include <iostream>
#include <fstream>

class FilePrinter : public Printer
{
public:
    FilePrinter(const char *file) : filename(file){}
    ~FilePrinter(){}
    void print(std::string toPrint);
private:
    const char *filename;
};

#endif // FILEPRINTER_H
