#include "matrix.h"
#include <iostream>
#include <string>
#include <sstream>

Matrix::Matrix(int rows, int columns)
{
    nRows = rows;
    nCols = columns;
    matrix = new int*[nCols];
    for (int i = 0; i < nCols; i++)
        matrix[i] = new int[nRows];

}


Matrix::~Matrix()
{
    for (int i = 0; i < nCols; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int **Matrix::pMatrix()
{
    return matrix;
}

void Matrix::fillMatrix()
{
    for (int i = 0; i < nRows * nCols; i++)
    {
        std::cin >> matrix[i % nCols][i / nCols];
    }
}

void Matrix::sortMatrix()
{
    Sorter *mSort = new QuickSort;
    mSort->sort(matrix, nCols);
    delete mSort;
}

void Matrix::showMatrix()
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
            std::cout << matrix[j][i] << '\t';
        std::cout << std::endl;
    }
}




