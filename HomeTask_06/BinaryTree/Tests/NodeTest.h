#ifndef NODETEST_H
#define NODETEST_H

#include <QObject>
#include <QtTest\QTest>
#include "BinaryTreeNode.h"

class NodeTest : public QObject
{
    Q_OBJECT
public:
    explicit NodeTest(QObject *parent = 0) : QObject(parent){}
private slots:
    void initTestCase()
    {
        BinaryTreeNode<int> node(5);
        QVERIFY(node.state() == BinaryTreeNode<int>::noChild);
    }

    void testValue()
    {
        BinaryTreeNode<int> node(5);
        QCOMPARE(node.value(), 5);
        node.setValue(3);
        QCOMPARE(node.value(), 3);
    }

    void testChildren()
    {
        BinaryTreeNode<int> node(5);
        BinaryTreeNode<int>* child = new BinaryTreeNode<int>(3);
        node.setLeft(child);
        QVERIFY(node.state() == BinaryTreeNode<int>::leftChildOnly);
        child = new BinaryTreeNode<int>(8);
        node.setRight(child);
        QVERIFY(node.state() == BinaryTreeNode<int>::bothChildren);
        QCOMPARE(node.left()->value(), 3);
        QCOMPARE(node.right()->value(), 8);
    }
    
    void testIncDec()
    {
        BinaryTreeNode<int> node(5);
        node++;
        QCOMPARE(node.value(), 5);
        QVERIFY(node.count() == 2);
        node--;
        QCOMPARE(node.value(), 5);
        QVERIFY(node.count() == 1);
        node--;
        QCOMPARE(node.value(), 5);
        QVERIFY(node.count() == 1);
    }

};

#endif // NODETEST_H
