#ifndef EXPRTREETEST_H
#define EXPRTREETEST_H

#include <QObject>
#include <QtTest/QTest>
#include "ExprTree.h"

class ExprTreeTest : public QObject
{
    Q_OBJECT

private slots:

    void testSimple()
    {
        writeTestFile("(+ 1 1)\n");
        parceTestFile(2);
    }

    void testNumberOnly()
    {
        writeTestFile("42\n");
        parceTestFile(42);
    }

    void testMedium()
    {
        writeTestFile("(+ (- 8 2)(/ 10 2)\n");
        parceTestFile(11);
    }

    void testHard()
    {
        writeTestFile("(/(* (+ 1 2) (/ 10 4)) (- 7 4))\n");
        parceTestFile(2.5);
    }

    void testCrash()
    {
        writeTestFile("( 15\n");
        parceTestFile(0);
    }

private:
    void writeTestFile(const char* expr)
    {
        std::ofstream testFile;
        testFile.open("test.txt", std::ios_base::out);
        testFile << expr;
        testFile.close();
    }
    void parceTestFile(double controlValue)
    {
        std::ifstream source;
        source.open("test.txt", std::ios_base::in);

        std::ofstream output;
        output.open("out.txt", std::ios_base::out);

        ExprTree counter;

        try
        {
            if ((source != NULL) && (output != NULL))
            {
                counter.parce(source, output);
                counter.printExprTree(output);

                QVERIFY(qFuzzyCompare(counter.count(), controlValue));
            }
        }
        catch(std::exception)
        {
            output << "\nExpression parce failed\n";
        }

        source.close();
        output.close();
    }
};



#endif // EXPRTREETEST_H
