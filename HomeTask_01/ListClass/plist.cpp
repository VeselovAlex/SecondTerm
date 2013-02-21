#include "plist.h"
#include <iostream>

PList::PList()
{
    head = nullptr;
}

void PList::add(int value)
{
    //PListEl box = new PListEl(value);

    if (isEmpty())
    {
       head = new PListEl(value);
       return;
    }

    if (value < (head.getValue()))
    {
        PList *tmp = head;
        head = new PListEl(value);
        head.next = *tmp;
        return;
    }

    if (head.isEnding())
    {
       head.next = new PListEl(value);
       return;
    }

    PListEl *temp = head;
    do
    {
        if (temp->next.getValue() > value)
        {
            PListEl *tmp = temp->next;
            temp->next = new PListEl(value);
            temp->next.next = tmp;
            return;
        }
        temp = temp->next;
    }
    while (!temp->isEnding());

    temp->next = new PListEl(value);
    return;


}

void PList::remove(int value)
{
    if (isEmpty())
        return;

    if (head.isEnding())
    {
        if (head.getValue() == value)
        {
            delete head;
            head = nullptr;
        }
        return;
    }

    PListEl *temp = head;
    do
    {
        if (temp->next.getValue() == value)
        {
            PListEl *temp2 = temp->next;
            temp->next = temp->next.next;
            temp2->next = nullptr;
            delete *temp2;
            return;
        }
        if (temp->next.getValue() > value)
            return;
        temp = temp->next;
    }
    while (!temp->isEnding());

}

void PList::printall()
{
    head.print();
}
