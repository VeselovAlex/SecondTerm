#include "slist.h"

SList::SList()
{
    head = NULL;
    size = 0;
    empty = true;
}

SList::~SList()
{
    if (!isEmpty())
        delete head;
}


void SList::add(int value)
{
    if (isEmpty())
        head = new ListBox(value);
    else if (head->getVal() >= value)
    {
        ListBox *temp = head;
        head = new ListBox(value);
        head->next = temp;
    }
    else
    {
        ListBox *temp = head;
        while ((!temp->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        ListBox* cont = temp->next;
        temp->next = new ListBox(value);
        temp->next->next = cont;
    }
    size++;
    empty = false;
}

void SList::remove(int value)
{
    if (isEmpty() || head->getVal() > value)
    {
        return;
    }
    else if (head->getVal() == value)
    {
        if (head->isEnding())
        {
            delete head;
            head = NULL;
            size = 0;
            empty = true;
            return;
        }
        ListBox *temp = head;
        head = head->next;
        temp->next = NULL;
        delete  temp;
        return;
    }
    else
    {
        ListBox *temp = head;
        while ((!temp->next->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        if (temp->next->getVal() == value)
        {
            ListBox* cont = temp->next;
            temp->next = temp->next->next;
            cont->next = NULL;
            delete cont;
            size--;
            empty = false;
        }
    }

}

void SList::printall()
{
    if (!isEmpty())
        head->print();
}
