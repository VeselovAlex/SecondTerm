#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <stdlib.h>


template <typename DataType>
class BinaryTreeNode
{
public:
    enum State
    {
        noChild = 0,
        rightChildOnly = 1,
        leftChildOnly = 2,
        bothChildren = 3
    };

    BinaryTreeNode(DataType value) :
        data(value),
        counter(1),
        leftChild(NULL),
        rightChild(NULL){}

    ~BinaryTreeNode()
    {
        delete leftChild;
        delete rightChild;
    }


    DataType value()
    {
        return data;
    }

    void setValue(DataType value)
    {
        data = value;
    }


    BinaryTreeNode*& left()
    {
        return leftChild;
    }

    void setLeft(BinaryTreeNode* node)
    {
        leftChild = node;
    }


    BinaryTreeNode*& right()
    {
        return rightChild;
    }

    void setRight(BinaryTreeNode* node)
    {
        rightChild = node;
    }


    unsigned int count()
    {
        return counter;
    }

    void setCount(unsigned int count)
    {
        counter = count;
    }

    void operator++(int)
    {
        counter++;
    }

    void operator--(int)
    {
        if (counter > 1)
            counter--;
    }

    State state()
    {
        if (leftChild == NULL)
            if (rightChild == NULL)
                return noChild;
            else
                return rightChildOnly;
        else
            if (rightChild == NULL)
                return leftChildOnly;
            else
                return bothChildren;
    }

private:
    DataType data;
    unsigned int counter;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

#endif // BINARYTREENODE_H
