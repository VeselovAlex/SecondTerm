#ifndef BUBBLESORTTEST_H
#define BUBBLESORTTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "bubblesort.h"

class BubbleSortTest : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void test_1()
    {
        BubbleSort sorter;
        int test[1] = {1};
        sorter.sort(test, 1);
        QCOMPARE(test[0], 1);
    }

    void testRevert()
    {
        BubbleSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = i;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], i);
    }

    void testSame()
    {
        BubbleSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = 666;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], 666);
    }

    void testFew()
    {
        BubbleSort sorter;
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

#endif // BUBBLESORTTEST_H
