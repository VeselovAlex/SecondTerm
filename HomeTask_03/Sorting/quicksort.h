#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sort.h"

class QuickSort : public Sorter
{
public:
    QuickSort();
    void sort(int array[], int size);

};

#endif // QUICKSORT_H
