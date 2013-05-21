#ifndef PAIROFINTCOMPARATOR_H
#define PAIROFINTCOMPARATOR_H

#include "Comparator.h"

struct PairOfInt
{
    int pair[2];
};

class PairOfIntComparator : public Comparator<PairOfInt>
{
public:
    PairOfIntComparator(Comparator<PairOfInt>::Order order = Comparator<PairOfInt>::Ascending) :
        Comparator<PairOfInt>(order){}
    int compare(PairOfInt firstOperand, PairOfInt secondOperand)
    {
        int result = currentOrder;
        if (firstOperand.pair[0] < secondOperand.pair[0])
            return result *= -1;
        else if ((firstOperand.pair[0] == secondOperand.pair[0]) && (firstOperand.pair[1] < secondOperand.pair[1]))
            return result *= -1;
        else if ((firstOperand.pair[0] == secondOperand.pair[0]) && (firstOperand.pair[1] == secondOperand.pair[1]))
            return 0;
        else
            return result;
    }
};

#endif // PAIROFINTCOMPARATOR_H
