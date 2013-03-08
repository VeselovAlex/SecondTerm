#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "sort.h"
#include <iostream>

class BubbleSort : public Sorter
{
public:
    BubbleSort();
    void sort(int array[], int size);
};

#endif // BUBBLESORT_H
