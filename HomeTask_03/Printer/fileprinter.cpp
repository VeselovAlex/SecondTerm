#include "fileprinter.h"
using namespace std;

void FilePrinter::print(std::string toPrint)
{
    ofstream file;
    file.open(filename, ios_base::app);
    file << toPrint;
    file.close();
}




