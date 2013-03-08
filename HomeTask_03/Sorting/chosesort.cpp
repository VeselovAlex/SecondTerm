#include "chosesort.h"
#include <iostream>

ChoseSort::ChoseSort()
{
    std::cout << "Creating chose sort ..." << std::endl;
}

void ChoseSort::sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = INT_MAX;
        int nMin = i;
        for(int j = i; j < size; j++)
            if (array[j] < min)
            {
                min = array[j];
                nMin = j;
            }
        std::swap(array[i], array[nMin]);
    }
}
