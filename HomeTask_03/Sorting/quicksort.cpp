#include "quicksort.h"
#include <iostream>

QuickSort::QuickSort()
{
    std::cout << "Creating quick sorter..." << std::endl;
}

void quicksort(int array[], int first, int last);

void QuickSort::sort(int array[], int size)
{
    quicksort(array, 0, size - 1);
}

void quicksort(int array[], int first, int last)
{
    int central = array[(last + first) / 2];
    int rightSlider = last;
    int leftSlider = first;
    do
    {
        while (array[leftSlider] < central)
        {
            ++leftSlider;
        }
        while (array[rightSlider] > central)
        {
            --rightSlider;
        }
        if (leftSlider <= rightSlider)
        {
            std::swap(array[leftSlider], array[rightSlider]);
            leftSlider++;
            rightSlider--;
        }

    }
    while (leftSlider < rightSlider);
    if (rightSlider > first)
        quicksort(array, first, rightSlider);
    if (last > leftSlider)
        quicksort(array, leftSlider, last);
}

