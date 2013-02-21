#include <iostream>
#include <plist.h>

using namespace std;

int main()
{
    cout << "Initialize Pointer List:" << endl;
    List *testList = new PList;
    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values:" << endl;
    int num;
    while (cin >> num)
    {
        cout << "Adding/t" << num;
        testList->add(num);
        cout << "/tSuccess" << endl;
    };
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter the values to remove:" << endl;
    while (cin >> num)
    {
        cout << "Removing/t" << num;
        testList->remove(num);
        cout << "/tSuccess" << endl;
    };
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Printing:" << endl;
    testList->printall();
    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Finish list:" << endl;
    delete testList;
    cout << "Success" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Type sth. to quit: " << endl;
    char q;
    cin >> q;

    return 0;
}

