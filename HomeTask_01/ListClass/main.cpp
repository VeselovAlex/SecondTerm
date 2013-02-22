#include <iostream>
#include "slist.h"

using namespace std;

int main()
{
    cout << "Initialize Pointer List:" << endl;
    List *testList = new SList;

    /*ListBox *first = new ListBox(15);
    ListBox *second = new ListBox (10);
    first->next = second;
    first->print();
    second->print();
    delete first;
    second->print();*/

    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values:" << endl;
    int num = 5;
    while (num != 0)
    {
        cin >> num;
        cout << "Adding\t" << num;
        testList->add(num);
        cout << "\tSuccess" << endl;
    };
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values to remove:" << endl;
    num = 5;
    while (num != 0)
    {
        cin >> num;
        cout << "Removing\t" << num;
        testList->remove(num);
        cout << "\tSuccess" << endl;
    };
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Printing:" << endl;
    testList->printall();
    cout << "\nSuccess" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Finish list:" << endl;
    delete testList;
    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Type sth. to quit: " << endl;

    return 0;
}

