#ifndef CHOSESORT_H
#define CHOSESORT_H
#include "sort.h"

/**
 * @brief The chose-sorting class for arrays of integers
 */
class ChoseSort : public Sorter
{
public:
    /**
     * @brief Constructor prints a message to console when running
     */
    ChoseSort();
    /**
     * @brief sort
     * @param array  The pointer to array
     * @param size The quantity of array elements
     */
     void sort (int array[], int size);
};

#endif // CHOSESORT_H
