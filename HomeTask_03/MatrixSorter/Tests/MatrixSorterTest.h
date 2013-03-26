#ifndef MATRIXSORTERTEST_H
#define MATRIXSORTERTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "matrix.h"

class MatrixSorterTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixSorterTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void initTestCase()
    {
        Matrix test(1, 1);
        QVERIFY(test.pMatrix() != NULL);
        QVERIFY(test.pMatrix()[0] != NULL);
    }

    void testSort_1_1()
    {
        Matrix test(1, 1);
        test.pMatrix()[0][0] = 1;
        test.sortMatrix();
        QCOMPARE(test.pMatrix()[0][0], 1);
    }

    void testSort_2_2()
    {
        Matrix test(2, 2);
        test.pMatrix()[0][0] = 4;
        test.pMatrix()[1][0] = 1;
        test.pMatrix()[0][1] = 1;
        test.pMatrix()[1][1] = 0;
        test.sortMatrix();

        QCOMPARE(test.pMatrix()[0][0], 1);
        QCOMPARE(test.pMatrix()[1][0], 4);
        QCOMPARE(test.pMatrix()[0][1], 0);
        QCOMPARE(test.pMatrix()[1][1], 1);
    }

};

QTEST_MAIN(MatrixSorterTest)
#endif // MATRIXSORTERTEST_H
