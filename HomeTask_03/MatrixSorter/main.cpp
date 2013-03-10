#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    int rows, cols;
    cout << "Type matrix ranges here (rows, columns): ";
    cin >> rows >> cols;
    cout << "Type matrix values here:" << endl;
    Matrix *test = new Matrix(rows, cols);
    test->fillMatrix();
    test->sortMatrix();
    test->showMatrix();

    delete test;
}

