#include "slist.h"

SingleList::SingleList()
{
    head = NULL;
    size = 0;
    empty = true;
}

SingleList::~SingleList()
{
    if (!isEmpty())
        delete head;
}


void SingleList::add(int value)
{
    if (isEmpty())
        head = new ListEl(value);
    else if (head->getVal() >= value)
    {
        ListEl *temp = head;
        head = new ListEl(value);
        head->next = temp;
    }
    else
    {
        ListEl *temp = head;
        while ((!temp->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        ListEl* cont = temp->next;
        temp->next = new ListEl(value);
        temp->next->next = cont;
    }
    size++;
    empty = false;
}

void SingleList::remove(int value)
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
        ListEl *temp = head;
        head = head->next;
        temp->next = NULL;
        delete  temp;
        return;
    }
    else
    {
        ListEl *temp = head;
        while ((!temp->next->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        if (temp->next->getVal() == value)
        {
            ListEl* cont = temp->next;
            temp->next = temp->next->next;
            cont->next = NULL;
            delete cont;
            size--;
            empty = false;
        }
    }

}

void SingleList::printall()
{
    if (!isEmpty())
        head->print();
}
