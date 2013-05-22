#ifndef VECTORTEST_H
#define VECTORTEST_H

#include <QObject>
#include <QtTest/Qtest>

#include "Vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        QVERIFY(!test.isNULLVector());
        QVERIFY(test[0] == 1);
        QVERIFY(test[1] == 2);
    }
    void testCopy()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        Vector<int> copy(test);
        QVERIFY(!copy.isNULLVector());
        QVERIFY(copy[0] == 1);
        QVERIFY(copy[1] == 2);
        test[0] = 2;
        QVERIFY(copy[0] == 1);
    }

    void testNULLVector()
    {
        int coord[2] = {0,0};
        Vector<int> test(coord, 2);
        QVERIFY(test.isNULLVector());
        Vector<int> copy(test);
        QVERIFY(copy.isNULLVector());
    }

    void testAdd()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        Vector<int> copy(test);
        Vector<int> sum = test + copy;
        QVERIFY(!sum.isNULLVector());
        QVERIFY(sum[0] == 2);
        QVERIFY(sum[1] == 4);
    }

    void testNegative()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        Vector<int> negative = -test;
        QVERIFY(!negative.isNULLVector());
        QVERIFY(negative[0] == -1);
        QVERIFY(negative[1] == -2);
    }

    void testSubtract()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        Vector<int> copy(test);
        Vector<int> sum = (test) - (copy);
        QVERIFY(sum.isNULLVector());
        sum = sum - copy;
        QVERIFY(!sum.isNULLVector());
        QVERIFY(sum[0] == -1);
        QVERIFY(sum[1] == -2);
    }

    void testScalarMultiply()
    {
        int coord[2] = {1,2};
        Vector<int> test(coord, 2);
        Vector<int> copy(test);
        int sum = test * copy;
        QVERIFY(sum == 5);

    }
};

#endif // VECTORTEST_H
