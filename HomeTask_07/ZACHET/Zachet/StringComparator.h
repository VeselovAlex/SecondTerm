#ifndef STRINGCOMPARATOR_H
#define STRINGCOMPARATOR_H
#include "Comparator.h"
#include <string>

class StringComparator : public Comparator<std::string>
{
public:
    StringComparator(Comparator<std::string>::Order order = Comparator<std::string>::Ascending) : Comparator<std::string>(order){}
    int compare(std::string firstOperand, std::string secondOperand)
    {
        int result = currentOrder;
        if (firstOperand < secondOperand)
            return result *= -1;
        else if (firstOperand == secondOperand)
            return 0;
        else
            return result;
    }
};

#endif // STRINGCOMPARATOR_H
