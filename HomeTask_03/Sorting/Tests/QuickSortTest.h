#ifndef QUICKSORTTEST_H
#define QUICKSORTTEST_H

#include <QObject>
#include <QTest>
#include "quicksort.h"

class QuickSortTest : public QObject
{
    Q_OBJECT
public:
    explicit QuickSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void test_1()
    {
        QuickSort sorter;
        int test[1] = {1};
        sorter.sort(test, 1);
        QCOMPARE(test[0], 1);
    }

    void testRevert()
    {
        QuickSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = i;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], i);
    }

    void testSame()
    {
        QuickSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = 666;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], 666);
    }

    void testFew()
    {
        QuickSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = (i % 2) * 2 + 4;
        sorter.sort(test, 10);
        for (int i = 0; i < 5; i++)
            QCOMPARE(test[i], 4);
        for (int i = 5; i < 10; i++)
            QCOMPARE(test[i], 6);
    }

};

#endif // QUICKSORTTEST_H
