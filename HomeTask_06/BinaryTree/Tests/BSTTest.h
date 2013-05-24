#ifndef BSTTEST_H
#define BSTTEST_H

#include <QtTest/QTest>
#include "BinarySearchTree.h"

class BSTTest : public QObject
{
    Q_OBJECT
public:
    explicit BSTTest(QObject *parent = 0) : QObject(parent){}
private slots:
    void initTestCase()
    {
        BinarySearchTree<int> tree;
        QVERIFY(tree.root() == NULL);
    }

    void testAdd()
    {
        BinarySearchTree<int> tree;
        tree.add(5);
        QVERIFY(tree.root() != NULL);
        QVERIFY(tree.root()->value() == 5);
        tree.add(3);
        QVERIFY(tree.root()->left()->value() == 3);
        tree.add(8);
        QVERIFY(tree.root()->right()->value() == 8);
        tree.add(1);
        QVERIFY(tree.root()->left()->left()->value() == 1);
        tree.add(4);
        QVERIFY(tree.root()->left()->right()->value() == 4);
        tree.add(3);
        QVERIFY(tree.root()->left()->value() == 3);
        QVERIFY(tree.root()->left()->count() == 2);

    }
    void testRemove()
    {
        BinarySearchTree<int> tree;
        tree.add(5);
        tree.add(3);
        tree.add(8);
        tree.add(1);
        tree.add(4);
        tree.add(3);
        tree.remove(4);
        QVERIFY(tree.root()->left()->right() == NULL);
        tree.remove(3);
        QVERIFY(tree.root()->left()->left() != NULL);
        QVERIFY(tree.root()->left()->value() == 3);
        QVERIFY(tree.root()->left()->count() == 1);
        tree.remove(3);
        QVERIFY(tree.root()->left() != NULL);
        QVERIFY(tree.root()->left()->value() == 1);
        tree.remove(5);
        QVERIFY(tree.root()->value() == 8);

    }

    void testFind()
    {
        BinarySearchTree<int> tree;
        tree.add(5);
        tree.add(3);
        QVERIFY(tree.find(5) == tree.root());
        QVERIFY(tree.find(3) == tree.root()->left());
        QVERIFY(tree.find(8) == NULL);
    }
};

#endif // BSTTEST_H
