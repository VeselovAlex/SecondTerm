#include <iostream>
#include "Test/SLListTest.h"
#include "Test/DLListTest.h"


int main(int argc, char* argv[])
{
    SLListTest testSingleList;
    QTest::qExec(&testSingleList);
    DLListTest testDoubleList;
    QTest::qExec(&testDoubleList);

    return 0;
}

