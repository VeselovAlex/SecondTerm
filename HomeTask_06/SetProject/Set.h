#ifndef SET_H
#define SET_H
#include "BinarySearchTree.h"
#include <QDebug>

template <typename DataType>
class Set
{
public:
    Set(BinarySearchTree<DataType>* data = new BinarySearchTree<DataType>()) : dataTree(data){}
    ~Set()
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
    void remove(DataType item) throw (std::exception)
    {
        try
        {
            dataTree->remove(item);
        }
        catch (std::exception)
        {
            throw;
        }
    }

    bool contains(DataType item)
    {
        return dataTree->find(item) != NULL;
    }
    /**
     * @brief unionOfSets
     *  Функция заменяет текуший обьект Set обьединением множеств set1 и set2
     *  Поддерживаются повторяющиеся элементы
     **/
    void unionOfSets(const Set<DataType>& set1, const Set<DataType>& set2)
    {
        delete dataTree;
        dataTree = new BinarySearchTree<DataType>();

        QList<DataType> set1Elem = set1.dataTree->preOrderDetour();

        foreach (DataType item, set1Elem)
        {
            add(item);
        }

        QList<DataType> set2Elem = set2.dataTree->preOrderDetour();

        for (int i = 0; i < set2Elem.size(); i++)
        {
            DataType item = set2Elem[i];
            BinaryTreeNode<DataType>* place = dataTree->find(item);
            if (place == NULL)
            {
                add(item);
            }

            else
            {
                unsigned int j = 0;
                while ((j < place->count()) && (place->value() == item) && (i < set2Elem.size()))
                {
                    i++;
                    if (i < set2Elem.size())
                        item = set2Elem[i];
                    j++;
                }

                while ((place->value() == item) && (i < set2Elem.size()))
                {
                    i++;

                    if (i < set2Elem.size())
                    {
                        item = set2Elem[i];
                        dataTree->add(item);
                    }
                }
                i--;
            }
        }

        qDebug() << dataTree->preOrderDetour();

    }

    /**
     * @brief unionOfSets
     *  Функция заменяет текуший обьект Set пересечением множеств set1 и set2
     *  Поддерживаются повторяющиеся элементы
     **/
    void intersect(const Set<DataType>& set1, const Set<DataType>& set2)
    {
        delete dataTree;
        dataTree = new BinarySearchTree<DataType>();

        QList<DataType> set1Elem = set1.dataTree->preOrderDetour();
        QList<DataType> set2Elem = set2.dataTree->preOrderDetour();

        foreach (DataType item, set1Elem)
        {
            if (set2Elem.contains(item))
            {
                add(item);
                set2Elem.removeOne(item);
            }
        }

        qDebug() << dataTree->preOrderDetour();
    }
private:
    BinarySearchTree<DataType>* dataTree;

};



#endif // SET_H
