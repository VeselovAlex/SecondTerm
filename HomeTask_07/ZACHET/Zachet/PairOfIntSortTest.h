#ifndef PAIROFINTSORTTEST_H
#define PAIROFINTSORTTEST_H

#include <QtTest\QTest>
#include "PairOfIntComparator.h"
#include <BubbleSorter.h>

class PairOfIntSortTest : public QObject
{
    Q_OBJECT
public:
    explicit PairOfIntSortTest(QObject *parent = 0);
    
signals:
    
private slots:
    void testAscending()
    {
        PairOfInt array[2];
        array[0].pair[0] = 1,
        array[0].pair[1] = 2,
        array[1].pair[0] = 1;
        array[1].pair[1] = 1;
        BubbleSorter<PairOfInt> test();
        Comparator<PairOfInt>* comp = new PairOfIntComparator();
        test.sort(array, 3, comp);
        QVERIFY(array[0].pair[1] == 1);
        QVERIFY(array[1].pair[1] == 2);
        delete comp;
    }

    void testDescending()
    {
        PairOfInt array[2];
        array[0].pair[0] = 1,
        array[0].pair[1] = 2,
        array[1].pair[0] = 1;
        array[1].pair[1] = 1;
        BubbleSorter<PairOfInt> test();
        Comparator<PairOfInt>* comp = new PairOfIntComparator(Comparator<PairOfInt>::Descending);
        test.sort(array, 3, comp);
        QVERIFY(array[0].pair[1] == 2);
        QVERIFY(array[1].pair[1] == 1);
        delete comp;
    }
    
};

#endif // PAIROFINTSORTTEST_H
