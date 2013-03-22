#include "listel.h"
#include <QDebug>
#include <iostream>

ListElement::ListElement(QString value)
{
    val = value;
    next = NULL;
    qDebug() << "Element " << val << " created\n";
}

ListElement::~ListElement()
{
    qDebug() << "Element " << val << " deleted\n";
    delete next;
}


QString ListElement::getVal() const
{
    return val;
}

void ListElement::setVal(QString value)
{
    val = value;
}

void ListElement::print()
{
    /*std::cout << val << '\n';
    if (!isEnding())
        next->print();*/
}

bool ListElement::isEnding() const
{
    return next == NULL;
}
