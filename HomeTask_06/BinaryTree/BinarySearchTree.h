#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Tree.h"

template <typename DataType>
class BinarySearchTree : public Tree<DataType>
{
public:
    BinarySearchTree() : rootNode(NULL), elemCounter(0){}
    ~BinarySearchTree()
    {
        delete rootNode;
    }

    BinaryTreeNode<DataType>* root()
    {
        return rootNode;
    }
    /**
     * @brief add Add value to BST (including multivalues)
     * @param value Item to add
     */
    virtual void add(DataType value)
    {
        addTo(rootNode, value);
        elemCounter++;
    }

    /**
     * @brief remove Remove value from BST (including multivalues)
     * @param value Item to remove
     */
    virtual void remove(DataType value) throw (std::exception)
    {
        try
        {
            remove(rootNode, value);
            elemCounter--;
        }
        catch(...){}
    }
    /**
     * @brief find
     *find the place of item in BST
     * @param value Item to find
     * @return BinaryTreeNode<DataType>* if value exists in BST, else returns NULL
     */
    virtual BinaryTreeNode<DataType>* find(DataType value)
    {
        BinaryTreeNode<DataType>* result = root();
        while (result != NULL)
        {
            if (result->value() == value)
                return result;

            if (result->value() > value)
                result = result->left();
            else
                result = result->right();
        }
        return NULL;
    }


private:
    void addTo(BinaryTreeNode<DataType>*& curRoot, DataType value)
    {
        if (curRoot == NULL)
        {
            curRoot = new BinaryTreeNode<DataType>(value);
            return;
        }

        if (value < curRoot->value())
            addTo(curRoot->left(), value);
        else if (value == curRoot->value())
            curRoot->operator ++(0);
        else
            addTo(curRoot->right(), value);
    }

    void remove(BinaryTreeNode<DataType>*& curRoot, DataType value) throw (std::exception)
    {
        if (curRoot == NULL)
        {
            throw std::exception();// Нет такого эл-та
        }

        if (value < curRoot->value())
            remove(curRoot->left(), value);
        else if (value > curRoot->value())
            remove(curRoot->right(), value);
        else
            if (curRoot->count() > 1)
                curRoot->operator --(0);
            else
                if (curRoot->state() == BinaryTreeNode<DataType>::noChild)
                {
                    delete curRoot;
                    curRoot = NULL;
                }
                else if (curRoot->state() == BinaryTreeNode<DataType>::leftChildOnly)
                {
                    BinaryTreeNode<DataType>* tmp = curRoot->left();
                    curRoot->setLeft(NULL);
                    delete curRoot;
                    curRoot = tmp;
                }
                else if (curRoot->state() == BinaryTreeNode<DataType>::rightChildOnly)
                {
                    BinaryTreeNode<DataType>* tmp = curRoot->right();
                    curRoot->setRight(NULL);
                    delete curRoot;
                    curRoot = tmp;
                }
                else
                {
                    BinaryTreeNode<DataType>*& tmp = leftMostChild(curRoot->right());
                    curRoot->setValue(tmp->value());
                    curRoot->setCount(tmp->count());
                    BinaryTreeNode<DataType>* temp = tmp;
                    tmp = temp->right();
                    temp->setRight(NULL);
                    delete temp;
                }
    }

    BinaryTreeNode<DataType>*& leftMostChild(BinaryTreeNode<DataType>* root)
    {
        BinaryTreeNode<DataType>* tmp = root;
        while(tmp->left() != NULL)
            tmp = tmp->left();
        return tmp;
    }

protected:
    BinaryTreeNode<DataType>* rootNode;
    unsigned int elemCounter;
};

#endif // BINARYSEARCHTREE_H
