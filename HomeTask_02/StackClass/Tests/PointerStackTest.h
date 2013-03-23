#ifndef POINTERSTACKTEST_H
#define POINTERSTACKTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "pointerstack.h"


class PointerStackTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerStackTest(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        PointerStack test;
        QVERIFY(test.isEmpty());
        QVERIFY(test.getSize() == 0);
    }

    void testPush()
    {
        PointerStack test;
        test.push(15);
        QVERIFY(test.getSize() == 1);
        QCOMPARE(test.peek(), 15.0);
    }

    void testPop()
    {
        PointerStack test;
        test.push(15);
        QCOMPARE(test.pop(), 15.0);
        QVERIFY(test.getSize() == 0);
        QVERIFY(test.isEmpty());
    }

    void testMultiPush()
    {
        PointerStack test;
        for (int i = 1; i <= 10; i++)
            test.push(i);
        for (int i = 10; i >=1; i--)
            QVERIFY(test.pop() == i);
    }
};

//QTEST_MAIN(PointerStackTest)

#endif // POINTERSTACKTEST_H
