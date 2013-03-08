#include "bubblesort.h"

BubbleSort::BubbleSort()
{
     std::cout << "Creating bubble sorter..." << std::endl;
}


void BubbleSort::sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
               std::swap(array[j], array[j - 1]);
}
