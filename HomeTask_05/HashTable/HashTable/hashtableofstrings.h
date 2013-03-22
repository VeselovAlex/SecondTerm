#pragma once
#include <QString>

#include "HashTable\hashfunctions.h"
#include "List/slist.h"
/**
 * @brief The class for hash table of QString
 */
class HashTableOfStrings
{
public:
    /**
     * @param maxCapacity The number of elements in table
     */
    HashTableOfStrings(int maxCapacity);
    ~HashTableOfStrings();
    void addItem(QString newItem);
    bool findItem(QString item);
    void removeItem(QString item);
    void viewStat();
    void recountStat();
    /**
     * @brief changing hash function for the table
     * @param hashFunc The pointer to hash function
     */
    void changeHashFunction(int (*hashFunc) (QString item, int mod));
private:
    int capacity;
    List** hTable;
    float loadFactor;
    long itemCounter;
    int freeCells;
    int colisionNumber;
    int maxColision;
    int (*hashFunction)(QString item, int mod);

};
