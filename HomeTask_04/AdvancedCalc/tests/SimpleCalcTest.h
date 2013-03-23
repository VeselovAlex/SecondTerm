#ifndef SIMPLECALCTEST_H
#define SIMPLECALCTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "calc/SimpleCalculator.h"

class SimpleCalcTest : public QObject
{
    Q_OBJECT
public:
    explicit SimpleCalcTest(QObject *parent = 0) : QObject(parent){}
    
signals:
    
private slots:
    void testPlus()
    {
        SimpleCalculator test;
        test.changeFirstOperand(2);
        test.changeSecondOperand(2);
        test.changeOperation("+");
        test.getResult();
        QCOMPARE(test.getRes(), 4.0);
    }

    void testMunus()
    {
        SimpleCalculator test;
        test.changeFirstOperand(6);
        test.changeSecondOperand(2);
        test.changeOperation("-");
        test.getResult();
        QCOMPARE(test.getRes(), 4.0);
    }

    void testMult()
    {
        SimpleCalculator test;
        test.changeFirstOperand(2);
        test.changeSecondOperand(2);
        test.changeOperation("*");
        test.getResult();
        QCOMPARE(test.getRes(), 4.0);
    }

    void testDiv()
    {
        SimpleCalculator test;
        test.changeFirstOperand(8);
        test.changeSecondOperand(2);
        test.changeOperation("/");
        test.getResult();
        QCOMPARE(test.getRes(), 4.0);
    }
    
};
QTEST_MAIN(SimpleCalcTest)


#endif // SIMPLECALCTEST_H
