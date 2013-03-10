#ifndef SORT_H
#define SORT_H
/**
 * @brief The Sorting class for arrays of pointers
 */
class Sorter//Sortir
{
public:
    /**
     * @brief deleting sorting class without deleting matrice
     */
    virtual ~Sorter(){}
    /**
     * @brief sort  abstract function for sorting matrix by the first string
     * @param array  The pointer to array of pointers
     * @param size The quantity of columns
     */
    virtual void sort(int *array[], int size) = 0;
};

#endif // SORT_H
