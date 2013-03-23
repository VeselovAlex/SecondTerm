#ifndef ARRAYSTACKTEST_H
#define ARRAYSTACKTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "arraystack.h"


class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackTest(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        ArrayStack test(15);
        QVERIFY(test.isEmpty());
        QVERIFY(test.getSize() == 0);
    }

    void testPush()
    {
        ArrayStack test(15);
        test.push(15);
        QVERIFY(test.getSize() == 1);
        QCOMPARE(test.peek(), 15.0);
    }

    void testPop()
    {
        ArrayStack test(15);
        test.push(15);
        QCOMPARE(test.pop(), 15.0);
        QVERIFY(test.getSize() == 0);
        QVERIFY(test.isEmpty());
    }

    void testMultiPush()
    {
        ArrayStack test(15);
        for (int i = 1; i <= 10; i++)
            test.push(i);
        for (int i = 10; i >=1; i--)
            QVERIFY(test.pop() == i);
    }
};

QTEST_MAIN(ArrayStackTest)

#endif // ARRAYSTACKTEST_H
