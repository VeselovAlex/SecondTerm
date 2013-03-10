#ifndef MATRIX_H
#define MATRIX_H
#include "quicksort.h"
/**
 * @brief The Matrix class
 */
class Matrix
{
public:
    /**
     * @brief Matrix constructor (of integers)
     * @param rows Number of Rows
     * @param columns Number of Columns
     */
    Matrix(int rows, int columns);
    /**
     * @brief Matrix destructor deletes array
     */

    ~Matrix();
    /**
     * @brief fillMatrix Fill matrix values (integers only)
     */
    void fillMatrix();
    /**
     * @brief sortMatrix Quick-sorts matrix
     */
    void sortMatrix();
    /**
     * @brief showMatrix Print matrix values to console
     */
    void showMatrix();
protected:
    int **matrix;
private:
    int nRows;/** Number of Rows */
    int nCols;/** Number of Columns */
};

#endif // MATRIX_H
