#include <iostream>
#include <string>
#include <sstream>
#include "fileprinter.h"
#include "consoleprinter.h"

using namespace std;

bool correctMatrix(const int size)
{
    if ((size <= 0) || !(size % 2))
        return false;
    else
        return true;
}

void printLayer(int **matrix, int layer, int size, int &vStart, int &hStart)
{
    if (hStart < 0)
        return;

    int hPos = hStart;
    int vPos = vStart;
    Printer *matrixPrinter = new ConsolePrinter();

    string printable = "";
    stringstream toString(printable, ios_base::out);


    for (; hPos < size - layer - 1; hPos++)
        toString << matrix[vPos][hPos] << ' ';
    for (; vPos < size - layer - 1; vPos++)
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


int main()
{
    int size;
    cout << "Type matrix size here : ";
    cin >> size;

    if (!correctMatrix(size))
    {
        cout << "Invalid argument" <<endl;
        return 1;
    }

    int **matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    cout << "Type matrix values here : " << endl;
    for (int i = 0; i < size * size; i++)
    {
        cin >> matrix[i / size][i % size];
    }

    const int topLayer = 0;
    int currLayer = size / 2;

    int hStart = size / 2;
    int vStart = hStart;

    cout << "Spiral printing: \n";
    while (currLayer >= topLayer)//Printing all layers
    {
        printLayer(matrix, currLayer, size, vStart, hStart);
        currLayer--;
    }

    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;

}

