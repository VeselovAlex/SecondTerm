#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    int rows, cols;
    cout << "Type matrix range here (Rows, Columns):\n";
    cin >> rows >> cols;
    Matrix *test = new Matrix(rows, cols);
    cout << "Type matrix values here:\n";
    test->fillMatrix();
    test->spiralPrint();
    delete test;
    return 0;

}

