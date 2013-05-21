#ifndef STRINGSORTTEST_H
#define STRINGSORTTEST_H
#include <QtTest/QTest>
#include "StringComparator.h"
#include "BubbleSorter.h"

class StringSortTest : public QObject
{
    Q_OBJECT
private slots:
    void testAscending()
    {
        std::string* str1 = new std::string[3];
        str1[0] = "Aecd";
        str1[1] = "ZXCvnb";
        str1[2] = "Bfhiuhjh";
        BubbleSorter<std::string> test();
        Comparator<std::string>* comp = new StringComparator();
        test.sort(str1, 3, comp);
        QVERIFY(str1[0] == "Aecd");
        QVERIFY(str1[1] == "Bfhiuhjh");
        QVERIFY(str1[2] == "ZXCvnb");
        delete str1;
        delete comp;
    }

    void testDescending()
    {
        std::string* str1 = new std::string[3];
        str1[0] = "Aecd";
        str1[1] = "ZXCvnb";
        str1[2] = "Bfhiuhjh";
        BubbleSorter<std::string> test();
        Comparator<std::string>* comp = new StringComparator(Comparator<std::string>::Descending);
        test.sort(str1, 3, comp);
        QVERIFY(str1[2] == "Aecd");
        QVERIFY(str1[1] == "Bfhiuhjh");
        QVERIFY(str1[0] == "ZXCvnb");
        delete str1;
        delete comp;
    }
};

#endif // STRINGSORTTEST_H
