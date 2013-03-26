#include "Tests.h"

using namespace std;

int main()
{
    BubbleSortTest testBubble;
    QTest::qExec(&testBubble);

    QuickSortTest testQuick;
    QTest::qExec(&testQuick);

    ChoseSortTest testChose;
    QTest::qExec(&testChose);
}

