#ifndef BAG_H
#define BAG_H
#include "BinarySearchTree.h"
#include <QDebug>
#include "Iterator.h"

template <typename DataType>
class Bag
{
public:
    Bag(BinarySearchTree<DataType>* data = new BinarySearchTree<DataType>()) : dataTree(data), iter(Iterator<DataType>(data)){}
    ~Bag()
    {
        delete dataTree;
    }

    /**
     * @brief add
     *  Добавление элемента в множество (оддерживаются повторяющиеся элементы)
     */
    void add(DataType item)
    {
        dataTree->add(item);
    }

    /**
     * @brief add
     *  Удаление элемента из множества (оддерживаются повторяющиеся элементы)
     */
    void remove(DataType item)
    {
        dataTree->remove(item);
    }

    bool contains(DataType item)
    {
        return dataTree->find(item) != NULL;
    }
    /**
     * @brief unionOfBags
     *  Функция заменяет текуший обьект Bag обьединением множеств Bag1 и Bag2
     *  Поддерживаются повторяющиеся элементы
     **/
    void unionOfBags(const Bag<DataType>& Bag1, const Bag<DataType>& Bag2)
    {
        delete dataTree;
        dataTree = new BinarySearchTree<DataType>();

        QList<DataType> Bag1Elem = Bag1.dataTree->preOrderDetour();

        foreach (DataType item, Bag1Elem)
        {
            add(item);
        }

        QList<DataType> Bag2Elem = Bag2.dataTree->preOrderDetour();

        for (int i = 0; i < Bag2Elem.size(); i++)
        {
            DataType item = Bag2Elem[i];
            BinaryTreeNode<DataType>* place = dataTree->find(item);
            if (place == NULL)
            {
                add(item);
            }

            else
            {
                unsigned int j = 0;
                while ((j < place->count()) && (place->value() == item) && (i < Bag2Elem.size()))
                {
                    i++;
                    if (i < Bag2Elem.size())
                        item = Bag2Elem[i];
                    j++;
                }

                while ((place->value() == item) && (i < Bag2Elem.size()))
                {
                    i++;

                    if (i < Bag2Elem.size())
                    {
                        item = Bag2Elem[i];
                        dataTree->add(item);
                    }
                }
                i--;
            }
        }

        qDebug() << dataTree->preOrderDetour();

    }

    /**
     * @brief unionOfBags
     *  Функция заменяет текуший обьект Bag пересечением множеств Bag1 и Bag2
     *  Поддерживаются повторяющиеся элементы
     **/
    void intersect(const Bag<DataType>& Bag1, const Bag<DataType>& Bag2)
    {
        delete dataTree;
        dataTree = new BinarySearchTree<DataType>();

        QList<DataType> Bag1Elem = Bag1.dataTree->preOrderDetour();
        QList<DataType> Bag2Elem = Bag2.dataTree->preOrderDetour();

        foreach (DataType item, Bag1Elem)
        {
            if (Bag2Elem.contains(item))
            {
                add(item);
                Bag2Elem.removeOne(item);
            }
        }

        qDebug() << dataTree->preOrderDetour();
    }

    Iterator<DataType> iterator()
    {
        return iter;
    }

private:
    BinarySearchTree<DataType>* dataTree;
    Iterator<DataType> iter;

};



#endif // BAG_H
