#ifndef SLLISTTEST_H
#define SLLISTTEST_H

#include <QObject>
#include <QTest>
#include "slist.h"

class SLListTest : public QObject
{
    Q_OBJECT
public:
    explicit SLListTest(QObject *parent = 0) : QObject(parent){}
private slots:
    void initTestCase()
    {
        SingleList test;
        QVERIFY(test.getHeadPointer() == NULL);
        QVERIFY(test.isEmpty());
        QVERIFY(test.getSize() == 0);
    }

    void testAdd()
    {
        SingleList test;
        test.add(5);
        QVERIFY(test.getSize() == 1);
        QVERIFY(!test.isEmpty());
        QVERIFY(test.getHeadPointer()->getVal() == 5);
    }

    void testMultiAdd()
    {
        SingleList test;
        test.add(5);
        test.add(3);
        test.add(2);
        test.add(1);
        test.add(4);
        test.add(6);
        QVERIFY(test.getSize() == 6);
        QVERIFY(!test.isEmpty());
        ListElement* iter = test.getHeadPointer();
        for (int i = 1; i <= 6; i++)
        {
            QVERIFY(iter->getVal() == i);
            iter = iter->next;
        }

        QVERIFY(iter == NULL);
    }

    void testRemove()
    {
        SingleList test;
        test.add(5);
        test.add(3);
        test.remove(3);
        QCOMPARE(test.getSize(), 1);
        QVERIFY(test.getHeadPointer()->getVal() == 5);
        test.remove(4);
        QVERIFY(test.getSize() == 1);
        QVERIFY(test.getHeadPointer()->getVal() == 5);

    }

    
};

//QTEST_MAIN(SLListTest)
#endif // SLLISTTEST_H
