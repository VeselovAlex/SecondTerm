#include <iostream>
#include "bubblesort.h"
#include "quicksort.h"
#include "chosesort.h"

using namespace std;

int main()
{
    int testArray[5] = {5,3,5,8,1};
    Sorter *test = new ChoseSort();
    test->sort(testArray,5);
    for (int i = 0; i < 5; i++)
        cout << testArray[i];
    delete test;
}

