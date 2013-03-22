#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include <QObject>
#include <QtTest/QTest>
#include "HashTable/hashtableofstrings.h"

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent){}
    
signals:
    
private slots:
    void testAdd()
    {
        HashTableOfStrings test(10);
        test.addItem("test");
        QVERIFY(test.findItem("test"));
    }

    void testRemove()
    {
        HashTableOfStrings test(10);
        test.addItem("test");
        test.removeItem("test");
        test.addItem("test2");
        QVERIFY(!test.findItem("test"));
    }

    
};
QTEST_MAIN(HashTableTest)
#endif // HASHTABLETEST_H
