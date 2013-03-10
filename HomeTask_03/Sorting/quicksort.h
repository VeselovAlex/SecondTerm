#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sort.h"

/**
 * @brief The quick(Hoar)-sorting class for arrays of integers
 */
class QuickSort : public Sorter
{
public:
    /**
     * @brief Constructor prints a message to console when running
     */
    QuickSort();
    /**
     * @brief sort
     * @param array The pointer to array
     * @param size The quantity of array elements
     */
    void sort(int array[], int size);

};

#endif // QUICKSORT_H
