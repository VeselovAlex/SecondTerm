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
    virtual void remove(DataType value)
    {
        remove(rootNode, value);
        elemCounter--;
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

    virtual QList<DataType> preOrderDetour()
    {
        return preOrderDetour(rootNode);
    }
    virtual QList<DataType> inOrderDetour()
    {
        return inOrderDetour(rootNode);
    }
    virtual QList<DataType> postOrderDetour()
    {
        return postOrderDetour(rootNode);
    }

private:
    void addTo(BinaryTreeNode<DataType>*& curRoot, DataType value);

    void remove(BinaryTreeNode<DataType>*& curRoot, DataType value);

    virtual QList<DataType> preOrderDetour(BinaryTreeNode<DataType>* root);
    virtual QList<DataType> inOrderDetour(BinaryTreeNode<DataType>* root);
    virtual QList<DataType> postOrderDetour(BinaryTreeNode<DataType>* root);

    BinaryTreeNode<DataType>* leftMostChild(BinaryTreeNode<DataType>* root)
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

template <typename DataType>
void BinarySearchTree<DataType>::remove(BinaryTreeNode<DataType> *&curRoot, DataType value)
{
    if (curRoot == NULL)
    {
        return;
    }

    if (value < curRoot->value())
        remove(curRoot->left(), value);
    else if (value > curRoot->value())
        remove(curRoot->right(), value);
    else
        if (curRoot->count() > 1)
            (*curRoot)--;
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
                BinaryTreeNode<DataType>* tmp = leftMostChild(curRoot->right());
                curRoot->setValue(tmp->value());
                curRoot->setCount(tmp->count());
                BinarySearchTree<DataType>::remove(curRoot->right(), tmp->value());

            }
    }

template <typename DataType>
void BinarySearchTree<DataType>::addTo(BinaryTreeNode<DataType> *&curRoot, DataType value)
{
    if (curRoot == NULL)
    {
        curRoot = new BinaryTreeNode<DataType>(value);
        return;
    }

    if (value < curRoot->value())
        addTo(curRoot->left(), value);
    else if (value == curRoot->value())
        (*curRoot)++;
    else
        addTo(curRoot->right(), value);
}

template <typename DataType>
QList<DataType> BinarySearchTree<DataType>::preOrderDetour(BinaryTreeNode<DataType>* root)
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

template <typename DataType>
QList<DataType> BinarySearchTree<DataType>::inOrderDetour(BinaryTreeNode<DataType>* root)
{
    if (root == NULL)
        return QList<DataType>();
    QList<DataType> list;
    if (root->left() != NULL)
        list << preOrderDetour(root->left());
    for (unsigned int i = 0; i < root->count(); i++)
    {
        list << root->value();
    }
    if (root->right() != NULL)
        list << preOrderDetour(root->right());
    return list;
}

template <typename DataType>
QList<DataType> BinarySearchTree<DataType>::postOrderDetour(BinaryTreeNode<DataType>* root)
{
    if (root == NULL)
        return QList<DataType>();
    QList<DataType> list;
    if (root->left() != NULL)
        list << preOrderDetour(root->left());
    if (root->right() != NULL)
        list << preOrderDetour(root->right());
    for (unsigned int i = 0; i < root->count(); i++)
    {
        list << root->value();
    }
    return list;
}
#endif // BINARYSEARCHTREE_H
