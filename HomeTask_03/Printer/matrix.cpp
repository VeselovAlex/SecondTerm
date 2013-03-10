#include "matrix.h"
#include <iostream>
#include <string>
#include <sstream>

Matrix::Matrix(int rows, int columns)
{
    nRows = rows;
    nCols = columns;
    matrix = new int*[nRows];
    for (int i = 0; i < nRows; i++)
        matrix[i] = new int[nCols];

}


Matrix::~Matrix()
{
    for (int i = 0; i < nRows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Matrix::fillMatrix()
{
    for (int i = 0; i < nRows * nCols; i++)
    {
        std::cin >> matrix[i / nCols][i % nCols];
    }
}

bool Matrix::correctMatrix()
{
    return ((nRows == nCols) && (nRows > 0) && (nRows % 2));
}

void Matrix::printLayer(int layer, int &vStart, int &hStart)
{
    if (hStart < 0)
        return;

    int hPos = hStart;
    int vPos = vStart;
    Printer *matrixPrinter = new ConsolePrinter();

    std::string printable = "";
    std::stringstream toString(printable, std::ios_base::out);


    for (; hPos < nCols - layer - 1; hPos++)
        toString << matrix[vPos][hPos] << ' ';
    for (; vPos < nRows - layer - 1; vPos++)
        toString << matrix[vPos][hPos] << ' ';
    for (; hPos > layer; hPos--)
        toString << matrix[vPos][hPos] << ' ';
    for (; vPos >= layer; vPos--)
        toString << matrix[vPos][hPos] << ' ';

    hStart = hPos;
    vStart = vPos;

    matrixPrinter->print(toString.str());
    delete matrixPrinter;

}

void Matrix::spiralPrint()
{
    if (!correctMatrix())
    {
        Printer *errPrint = new ConsolePrinter;
        errPrint->print("Invalid matrix");
        delete errPrint;
        return;
    }

    const int topLayer = 0;
    int currLayer = nRows / 2;

    int hStart = nCols / 2;
    int vStart = hStart;

    while (currLayer >= topLayer)//Printing all layers
    {
        printLayer(currLayer, vStart, hStart);
        currLayer--;
    }

}


