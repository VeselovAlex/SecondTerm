#include <iostream>
#include "pointerstack.h"
#include "arraystack.h"
//#include "getdouble.h"

using namespace std;

bool isOper (char ch)
{
    return ((ch == '+') || (ch == '-') ||(ch == '/') || (ch == '*'));
}

double operation (double oper1, double oper2, char operation)
{
    if (operation == '+')
        return (oper1 + oper2);
    if (operation == '-')
        return (oper1 - oper2);
    if (operation == '*')
        return (oper1 * oper2);
    if (operation == '/' && (oper2 != 0))
        return (oper1 / oper2);
    return 0;
}

int priority(char oper)
{
    if (oper == '+'|| oper == '-')
        return 1;
    if (oper == '*'|| oper == '/')
        return 2;
    return 0;
}

int calculator()
{
    Stack* operators = new ArrayStack(128);
    Stack* numbers = new PointerStack;
    int addition = 0;

    double number = 0;
    char oper = ' ';

    oper = cin.get();
    if (oper == '-')
    {
        cin.putback(oper);
        cin >> number;
        numbers->push(number);
    }
    while (oper != '=') //nice smile!
    {
        if ((oper >= '0') && (oper <= '9'))
        {
            cin.putback(oper);
            cin >> number;
            numbers->push(number);
        }
        else
        {
            if(isOper(oper))
            {
                if (operators->isEmpty())
                    operators->push(oper);
                else
                {
                    int currPriority = priority(operators->peek());
                    if (priority(oper) > currPriority)
                        operators->push(oper);
                    else
                    {
                        double result = operation(numbers->pop(), numbers->pop(), operators->pop());
                        numbers->push(result);
                        operators->push(oper);
                    };
                }
            }
        }
        oper = cin.get();
    }
    double result = operation(numbers->pop(), numbers->pop(), operators->pop());
    while(!operators->isEmpty())
        result = operation(result, numbers->pop(), operators->pop());

    cout << result;

    delete numbers;
    delete operators;
    return 0;

}
int main()
{
    calculator();
    return 0;
}
