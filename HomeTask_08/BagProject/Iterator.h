#ifndef ITERATOR_H
#define ITERATOR_H
#include <QList>
#include "BinarySearchTree.h"

template <typename DataType>
class Iterator
{
public:
    Iterator(BinarySearchTree<DataType>* tree) : source(tree), pos(0)
    {
        elemList = source->inOrderDetour();
    }
    /**
     * @brief next
     *return current item and switches to next item if it exists
     * @return DataType current item
     */

    DataType next()
    {
        if (hasNext())
            return elemList[pos++];
        else
        {
            return elemList[pos];
        }
    }
    /**
     * @brief hasNext
     * @return Returns "true" if current item has next item, otherwise returns "false"
     */
    bool hasNext()
    {
        return (!elemList.isEmpty()) && (pos < (elemList.size() - 1));
    }

    /**
     * @brief add Add item to Bag
     * @param item Item to add
     */
    void add(DataType item)
    {
        source->add(item);
        elemList = source->inOrderDetour();
        if ((item <= elemList[pos]) && hasNext())//New item added before current item
           pos++;
    }
    /**
     * @brief remove Removes current Item from Bag ind switches to next item if it exists
     */

    void remove()
    {
        if (elemList.isEmpty())
            return;
        DataType buffer = elemList[pos];
        source->remove(next());
        elemList = source->inOrderDetour();
        if (elemList[pos] <= buffer)//New item added before current item
            pos--;
    }

    /**
     * @brief flush switches iterator to first item
     */
    void flush()
    {
        pos = 0;
    }

private:
    QList<DataType> elemList;
    BinarySearchTree<DataType>* source;
    unsigned int pos;
};

#endif // ITERATOR_H
