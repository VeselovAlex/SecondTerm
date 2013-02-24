#include "doublelist.h"
#include <iostream>

DoubleList::DoubleList()
{
    head = NULL;
    size = 0;
    empty = true;
}

DoubleList::~DoubleList()
{
    if(!isEmpty())
        delete head;
}

void DoubleList::add(int value)
{
    if (isEmpty())
        head = new DoubleListEl(value);
    else if (head->getVal() >= value)
    {
        head->prev = new DoubleListEl(value);
        head->prev->next = head;
        head = head->prev;
    }
    else
    {
        DoubleListEl *temp = head;
        while ((!temp->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        if (temp->isEnding())
        {
            temp->next = new DoubleListEl(value);
            temp->next->prev = temp;
        }
        else
        {
            temp->next->prev = new DoubleListEl(value);
            temp->next->prev->prev = temp;
            temp->next->prev->next = temp->next;
            temp->next = temp->next->prev;
        }
    }
    size++;
    empty = false;
}

void DoubleList::remove(int value)
{
    if (isEmpty() || head->getVal() > value)
        return;
    DoubleListEl *temp = head;
    while (temp->getVal() < value)
        temp = temp->next;
    if (temp->getVal() > value)
        return;
    if (temp == head)
        head = head->next;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->next = NULL;
    delete temp;
    size --;
    if(head == NULL)
        empty = true;
}

void DoubleList::printall()
{
    if(!isEmpty())
        head->print();
}
