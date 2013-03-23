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
        head = new ListElement(value);
    else if (head->getVal() >= value)
    {
        ListElement *temp = head;
        head = new ListElement(value);
        head->next = temp;
    }
    else
    {
        ListElement *temp = head;
        while ((!temp->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        ListElement* cont = temp->next;
        temp->next = new ListElement(value);
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
        ListElement *temp = head;
        head = head->next;
        temp->next = NULL;
        delete  temp;
        size--;
        return;
    }
    else
    {
        ListElement *temp = head;
        while ((!temp->next->isEnding()) && (temp->next->getVal() < value))
            temp = temp->next;
        if (temp->next->getVal() == value)
        {
            ListElement* cont = temp->next;
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

ListElement *SingleList::getHeadPointer()
{
    return head;
}
