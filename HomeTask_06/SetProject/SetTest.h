#ifndef SETTEST_H
#define SETTEST_H

#include <QObject>
#include <QTest>
#include "Set.h"

class SetTest : public QObject
{
    Q_OBJECT

private slots:
    void testAdd()
    {
        Set<int> testSet;
        testSet.add(3);
        testSet.add(3);
        testSet.add(8);
        QVERIFY(testSet.contains(3));
        QVERIFY(testSet.contains(8));
        QVERIFY(!testSet.contains(2));
        QVERIFY(!testSet.contains(0));
    }
    void testRemove()
    {
        Set<int> testSet;
        testSet.add(3);
        testSet.add(3);
        testSet.add(8);
        testSet.remove(3);
        QVERIFY(testSet.contains(3));
        testSet.remove(8);
        QVERIFY(!testSet.contains(8));
        QVERIFY(!testSet.contains(2));
        QVERIFY(!testSet.contains(0));
    }

    void testUnion()
    {
        Set<int> set1;
        set1.add(1);
        set1.add(2);
        set1.add(2);
        set1.add(4);

        Set<int> set2;
        set2.add(1);
        set2.add(2);
        set2.add(2);
        set2.add(2);
        set2.add(3);

        Set<int> set3;
        set3.unionOfSets(set1, set2);
        QVERIFY(set3.contains(1));
        QVERIFY(set3.contains(2));
        QVERIFY(set3.contains(3));
        QVERIFY(set3.contains(4));

    }

    void testIntersect()
    {
        Set<int> set1;
        set1.add(1);
        set1.add(2);
        set1.add(2);
        set1.add(4);

        Set<int> set2;
        set2.add(1);
        set2.add(2);
        set2.add(2);
        set2.add(2);
        set2.add(3);

        Set<int> set3;
        set3.intersect(set1, set2);
        QVERIFY(set3.contains(1));
        QVERIFY(set3.contains(2));
        QVERIFY(!set3.contains(3));
        QVERIFY(!set3.contains(4));

    }
};

#endif // SETTEST_H
