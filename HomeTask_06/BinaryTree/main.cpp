#include <iostream>
#include <fstream>
#include "Tests/NodeTest.h"
#include "Tests/BSTTest.h"
#include "Tests/ExprTreeTest.h"

using namespace std;

int main()
{
    ExprTreeTest test;
    QTest::qExec(&test);

}

