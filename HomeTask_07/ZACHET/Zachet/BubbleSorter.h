#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include "Comparator.h"
#include <cstdlib>
#include <cstring>

template <typename DataType>
class BubbleSorter
{
public:
    void sort(DataType* dataArray, int size, Comparator<DataType>* comparator)
    {
        for (int i = 0; i < size; i++)
            for (int j = i; j < size; j++)
            {
                if (comparator->compare(dataArray[i], dataArray[j]) == -1)
                    swap(dataArray[1], dataArray[2]);
            }
    }
};

#endif // BUBBLESORTER_H
