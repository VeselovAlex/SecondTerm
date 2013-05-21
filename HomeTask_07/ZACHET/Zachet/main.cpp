#include <iostream>
#include "StringSortTest.h"
#include "PairOfIntSortTest.h"
#include "BubbleSorter.h"

using namespace std;

int main()
{
    StringSortTest strTest;
    PairOfIntSortTest pairTest;
    QTest::qExec(&strTest);
    QTest::qExec(&pairTest);

}

