#ifndef BAGTEST_H
#define BAGTEST_H

#include <QObject>
#include <QTest>
#include "Bag.h"

class BagTest : public QObject
{
    Q_OBJECT

private slots:
    void testAdd()
    {
        Bag<int> testBag;
        testBag.add(3);
        testBag.add(3);
        testBag.add(8);
        QVERIFY(testBag.contains(3));
        QVERIFY(testBag.contains(8));
        QVERIFY(!testBag.contains(2));
        QVERIFY(!testBag.contains(0));
    }
    void testRemove()
    {
        Bag<int> testBag;
        testBag.add(3);
        testBag.add(3);
        testBag.add(8);
        testBag.remove(3);
        QVERIFY(testBag.contains(3));
        testBag.remove(8);
        QVERIFY(!testBag.contains(8));
        QVERIFY(!testBag.contains(2));
        QVERIFY(!testBag.contains(0));
    }

    void testUnion()
    {
        Bag<int> Bag1;
        Bag1.add(1);
        Bag1.add(2);
        Bag1.add(2);
        Bag1.add(4);

        Bag<int> Bag2;
        Bag2.add(1);
        Bag2.add(2);
        Bag2.add(2);
        Bag2.add(2);
        Bag2.add(3);

        Bag<int> Bag3;
        Bag3.unionOfBags(Bag1, Bag2);
        QVERIFY(Bag3.contains(1));
        QVERIFY(Bag3.contains(2));
        QVERIFY(Bag3.contains(3));
        QVERIFY(Bag3.contains(4));

    }

    void testIntersect()
    {
        Bag<int> Bag1;
        Bag1.add(1);
        Bag1.add(2);
        Bag1.add(2);
        Bag1.add(4);

        Bag<int> Bag2;
        Bag2.add(1);
        Bag2.add(2);
        Bag2.add(2);
        Bag2.add(2);
        Bag2.add(3);

        Bag<int> Bag3;
        Bag3.intersect(Bag1, Bag2);
        QVERIFY(Bag3.contains(1));
        QVERIFY(Bag3.contains(2));
        QVERIFY(!Bag3.contains(3));
        QVERIFY(!Bag3.contains(4));

    }

    void testIterator()
    {
        Bag<unsigned int> testBag;
        Iterator<unsigned int> testIter = testBag.iterator();

//        testIter.add(5);
//        QVERIFY(testIter.next() == 5);
//        QVERIFY(!testIter.hasNext());
//        testIter.add(7);
//        QVERIFY(testIter.next() == 5);
//        QVERIFY(!testIter.hasNext());
//        QVERIFY(testIter.next() == 7);
//        QVERIFY(!testIter.hasNext());

        for (unsigned int i = 1; i < 6; i++)
        {
            testIter.add(i);
            testIter.next();
            QVERIFY(testIter.next() == i);
            testIter.add(i);
            QVERIFY(testIter.next() == i);
        }

        QVERIFY(!testIter.hasNext());
        testIter.add(8);
        QVERIFY(testIter.hasNext());

        testIter.flush();
        for (unsigned int i = 1; i < 4; i++)
        {
            testIter.next();
        }
        testIter.remove();
        QVERIFY(testIter.next() == 3);
        QVERIFY(testIter.next() == 4);
        testIter.add(2);
        testIter.add(2);
        testIter.add(7);
        QVERIFY(testIter.next() == 4);
        QVERIFY(testIter.next() == 5);
    }
};

#endif // BAGTEST_H
