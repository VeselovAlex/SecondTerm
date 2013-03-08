#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent)
{
    QObject::connect(this, SIGNAL(firstOperandChanged(int)),
                     this, SLOT(getResult()));
    QObject::connect(this, SIGNAL(secondOperandChanged(int)),
                     this, SLOT(getResult()));
    QObject::connect(this, SIGNAL(operationChanged(QString)),
                     this, SLOT(getResult()));
}


void Calculator::changeFirstOperand(int value)
{
    if (value != firstOperand)
    {
        firstOperand = value;
        emit firstOperandChanged(value);
    }
}

void Calculator::changeSecondOperand(int value)
{
    if (value != secondOperand)
    {
        secondOperand = value;
        emit secondOperandChanged(value);
    }
}

void Calculator::changeOperation(QString newOperation)
{
    if (operation != newOperation)
    {
        operation = newOperation;
        emit operationChanged(operation);
    }
}

void Calculator::getResult()
{
    resultToShow.setNum(result);
    double preResult = result;
    if (operation == "+")
        preResult = firstOperand + secondOperand;
    if (operation == "-")
        preResult = firstOperand - secondOperand;
    if (operation == "*")
        preResult = firstOperand * secondOperand;
    if ((operation == "/") && (secondOperand != 0))
        preResult = (double)firstOperand / (double)secondOperand;
    else
        resultToShow = "E";

    if (result != preResult)
    {
        result = preResult;
        resultToShow.setNum(result,'f',2);
        emit resultChanged(result);
    }
    emit resultChanged(resultToShow);

}
