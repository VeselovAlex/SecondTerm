#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename DataType>
class Comparator
{
public:
    enum Order
    {
        Ascending = 1,
        Descending = -1
    };

public:
    Comparator(Order order = Ascending) : currentOrder(order){}
    int compare(DataType firstOperand, DataType secondOperand){}
protected:
    Order currentOrder;
};

#endif // COMPARATOR_H
