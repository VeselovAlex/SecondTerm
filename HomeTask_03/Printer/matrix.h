#ifndef MATRIX_H
#define MATRIX_H
#include "consoleprinter.h"
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
     * @brief spiralPrint Printing matrix in spiral order (only for square matrices
     * with odd numbers of row and columns)
     */
    void spiralPrint();
protected:
    int **matrix;
private:
    /**
     * @brief correctMatrix checks matrix's printability
     */
    bool correctMatrix();
    /**
     * @brief printLayer prints onr square layer of square matrix
     * @param layer number of layer
     * @param vStart row of start element
     * @param hStart column of start element
     */
    void printLayer(int layer, int &vStart, int &hStart);
    int nRows;/** Number of Rows */
    int nCols;/** Number of Columns */
};

#endif // MATRIX_H
