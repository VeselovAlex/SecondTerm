#ifndef TREE_H
#define TREE_H
#include "BinaryTreeNode.h"
#include <exception>

template <typename DataType>
class Tree
{
public:
    virtual ~Tree(){}
    virtual void add(DataType value) = 0;
    virtual void remove(DataType value) throw (std::exception) = 0;
    virtual BinaryTreeNode<DataType>* find(DataType value) = 0;

};

#endif // TREE_H
