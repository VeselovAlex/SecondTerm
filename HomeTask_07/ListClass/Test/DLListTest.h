#ifndef DLLISTTEST_H
#define DLLISTTEST_H

#include <QObject>
#include <QTest>
#include "doublelist.h"

class DLListTest : public QObject
{
    Q_OBJECT
public:
    explicit DLListTest(QObject *parent = 0) : QObject(parent){}
private slots:
    void initTestCase()
    {
        DoubleList test;
        QVERIFY(test.getHeadPointer() == NULL);
        QVERIFY(test.isEmpty());
        QVERIFY(test.getSize() == 0);
    }

    void testAdd()
    {
        DoubleList test;
        test.add(5);
        QVERIFY(test.getSize() == 1);
        QVERIFY(!test.isEmpty());
        QVERIFY(test.getHeadPointer()->getVal() == 5);
    }

    void testExcAdd()
    {
        DoubleList test;
        test.add(5);
        try
        {
            test.add(5);
            QFAIL("Exception ignored\n");
        }
        catch (DataExistsException){};

    }

    void testMultiAdd()
    {
        DoubleList test;
        test.add(5);
        test.add(3);
        test.add(2);
        test.add(1);
        test.add(4);
        test.add(6);
        QVERIFY(test.getSize() == 6);
        QVERIFY(!test.isEmpty());

        DoubleListElement* iter = test.getHeadPointer();
        for (int i = 1; i < 6; i++)
        {
            QVERIFY(iter->getVal() == i);
            iter = iter->next;
        }
        QVERIFY(iter->getVal() == 6);
        QVERIFY(iter->next == NULL);

        for (int i = 6; i >= 1; i--)
        {
            QVERIFY(iter->getVal() == i);
            iter = iter->prev;
        }

        QVERIFY(iter == NULL);
    }

    void testRemove()
    {
        DoubleList test;
        test.add(5);
        test.add(3);
        test.remove(3);
        QCOMPARE(test.getSize(), 1);
        QVERIFY(test.getHeadPointer()->getVal() == 5);
        try
        {
            test.remove(4);
            QFAIL("Exception ignored\n");
        }
        catch (DataNotFoundException){};
    }
    void testRemovingFromEmptyExc()
    {
        DoubleList test;
        try
        {
            test.remove(42);
            QFAIL("Exception ignored\n");
        }
        catch (EmptyContainerException){};
    }

    
};
#endif // DLLISTTEST_H
