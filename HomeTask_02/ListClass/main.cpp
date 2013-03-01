#include <iostream>
#include "doublelist.h"

using namespace std;

int main()
{
    cout << "Initialize Pointer List:" << endl;
    List *testList = new DoubleList;
    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values:" << endl;
    int num = 5;
    cin >> num;
    while (num != 0)
    {
        cout << "Adding\t" << num;
        testList->add(num);
        cout << "\tSuccess" << endl;
        cin >> num;
    };
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values to remove:" << endl;
    cin >> num;
    while (num != 0)
    {
        cout << "Removing\t" << num;
        testList->remove(num);
        cout << "\tSuccess" << endl;
        cin >> num;
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

