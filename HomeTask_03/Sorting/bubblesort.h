#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "sort.h"
#include <iostream>

/**
 * @brief The bubble-sorting class for arrays of integers
 */
class BubbleSort : public Sorter
{
public:
    /**
     * @brief Constructor prints a message to console when running
     */
    BubbleSort();
    /**
     * @brief sort  abstract function for sorting array
     * @param array  The pointer to array
     * @param size The quantity of array elements
     */
    void sort(int array[], int size);
};

#endif // BUBBLESORT_H
