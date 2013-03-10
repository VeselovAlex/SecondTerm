#ifndef SORT_H
#define SORT_H
/**
 * @brief The Sorting class for arrays of integers
 */
class Sorter//Sortir
{
public:
    /**
     * @brief deleting sorting class without deleting arrray
     */
    virtual ~Sorter(){}
    /**
     * @brief sort  abstract function for sorting array
     * @param array  The pointer to array
     * @param size The quantity of array elements
     */
    virtual void sort(int array[], int size) = 0;
};

#endif // SORT_H
