#ifndef CHOSESORTTEST_H
#define CHOSESORTTEST_H

#include <QObject>
#include <QTest>
#include "chosesort.h"

class ChoseSortTest : public QObject
{
    Q_OBJECT
public:
    explicit ChoseSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void test_1()
    {
        ChoseSort sorter;
        int test[1] = {1};
        sorter.sort(test, 1);
        QCOMPARE(test[0], 1);
    }

    void testRevert()
    {
        ChoseSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = i;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], i);
    }

    void testSame()
    {
        ChoseSort sorter;
        int test[10];
        for (int i = 9; i >= 0; i--)
            test[i] = 666;
        sorter.sort(test, 10);
        for (int i = 0; i < 10; i++)
            QCOMPARE(test[i], 666);
    }

    void testFew()
    {
        ChoseSort sorter;
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

#endif // CHOSESORTTEST_H
