#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Tree.h"
#include <QList>

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

    virtual void add(DataType value)
    {
        addTo(rootNode, value);
        elemCounter++;
    }

    virtual void remove(DataType value) throw (std::exception)
    {
        try
        {
            remove(rootNode, value);
            elemCounter--;
        }
        catch(...){}
    }
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


    virtual QList<DataType> preOrderDetour()
    {
        return preOrderDetour(rootNode);
    }

    virtual QList<DataType> inOrderDetour()
    {
        return inOrderDetour(rootNode);
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

    virtual QList<DataType> preOrderDetour(BinaryTreeNode<DataType>* root)
    {
        if (root == NULL)
            return QList<DataType>();
        QList<DataType> list;
        for (unsigned int i = 0; i < root->count(); i++)
        {
            list << root->value();
        }
        if (root->left() != NULL)
            list << preOrderDetour(root->left());
        if (root->right() != NULL)
            list << preOrderDetour(root->right());
        return list;
    }

    virtual QList<DataType> inOrderDetour(BinaryTreeNode<DataType>* root)
    {
        if (root == NULL)
            return QList<DataType>();
        QList<DataType> list;

        if (root->left() != NULL)
            list << inOrderDetour(root->left());
        for (unsigned int i = 0; i < root->count(); i++)
        {
            list << root->value();
        }
        if (root->right() != NULL)
            list << inOrderDetour(root->right());
        return list;
    }
protected:
    BinaryTreeNode<DataType>* rootNode;
    unsigned int elemCounter;
};

#endif // BINARYSEARCHTREE_H
