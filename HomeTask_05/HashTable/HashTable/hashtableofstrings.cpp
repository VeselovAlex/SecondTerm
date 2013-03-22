#include <QDebug>
#include "hashtableofstrings.h"

HashTableOfStrings::HashTableOfStrings(int maxCapacity) :
    capacity(maxCapacity)
{
    capacity = maxCapacity;
    hTable = new List*[capacity];
    for (int i = 0; i < capacity; i++)
        hTable[i] = new SingleList();
    loadFactor = 0;
    itemCounter = 0;
    freeCells = maxCapacity;
    colisionNumber = 0;
    maxColision = 0;
    hashFunction = polynomeHash;
    qDebug() << "Hashtable created\n";

}

HashTableOfStrings::~HashTableOfStrings()
{
    for (int i = 0; i < capacity; i++)
        delete hTable[i];
    delete[] hTable;
    qDebug() << "HashTable destroyed";
}

void HashTableOfStrings::addItem(QString newItem)
{
    int hash = hashFunction(newItem, capacity);
    hTable[hash]->add(newItem);
    itemCounter++;
    if (itemCounter % 50 == 0)//Пересчет статистики через каждые 50 элементов
        recountStat();
    if (hTable[hash]->getSize() == 1)// Заполнена свободная ячейка
        freeCells--;
}

bool HashTableOfStrings::findItem(QString item)
{
    int hash = hashFunction(item, capacity);
    return hTable[hash]->checkValue(item);
}


void HashTableOfStrings::removeItem(QString item)
{
    int hash = hashFunction(item, capacity);
    bool checker = hTable[hash]->checkValue(item);

    if (!checker)// Проверим наличие данного элемента
        return;
    hTable[hash]->remove(item);
    itemCounter--;
    if (hTable[hash]->isEmpty())// Заполнена свободная ячейка
        freeCells++;
}

void HashTableOfStrings::viewStat()
{
    recountStat();
    qDebug() << "Hashtable capacity:\t" << capacity << '\n';
    qDebug() << "Item quantity:\t" << itemCounter << '\n';
    qDebug() << "Free cells:\t" << freeCells << '\n';
    qDebug() << "Load-factor:\t" << loadFactor << '\n';
    qDebug() << "Number of collisions:\t" << colisionNumber << '\n';
    qDebug() << "Max collision:\t" << maxColision - 1 << '\n';
}

void HashTableOfStrings::recountStat()
{
    for (int i = 0; i < capacity; i++)
    {
        if (hTable[i]->getSize() > maxColision)
            maxColision = hTable[i]->getSize();
    }
    colisionNumber = itemCounter - capacity + freeCells;
    loadFactor = (double)itemCounter / (double)capacity;

}

void HashTableOfStrings::changeHashFunction(int (*hashFunc)(QString, int))
{
    hashFunction = hashFunc;
}
