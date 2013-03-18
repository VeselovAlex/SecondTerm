#include "SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(QObject *parent) :
    QObject(parent), firstOperand(0), secondOperand(0), operation(""), result(0), resultToShow("")
{
    /*QObject::connect(this, SIGNAL(firstOperandChanged(int)),
                     this, SLOT(getResult()));
    QObject::connect(this, SIGNAL(secondOperandChanged(int)),
                     this, SLOT(getResult()));
    QObject::connect(this, SIGNAL(operationChanged(QString)),
                     this, SLOT(getResult()));*/
}

double SimpleCalculator::getRes()
{
    return result;
}


void SimpleCalculator::changeFirstOperand(double value)
{
    if (value != firstOperand)
    {
        firstOperand = value;
        emit firstOperandChanged(value);
    }
}

void SimpleCalculator::changeSecondOperand(double value)
{
    if (value != secondOperand)
    {
        secondOperand = value;
        emit secondOperandChanged(value);
    }
}

void SimpleCalculator::changeOperation(QString newOperation)
{
    if (operation != newOperation)
    {
        operation = newOperation;
        emit operationChanged(operation);
    }
}

void SimpleCalculator::getResult()
{
    resultToShow.setNum(result, 'f', 2);
    double preResult = result;
    if (operation == "+")
        preResult = firstOperand + secondOperand;
    else if (operation == "-")
        preResult = firstOperand - secondOperand;
    else if (operation == "*")
        preResult = firstOperand * secondOperand;
    else if ((operation == "/") && (secondOperand != 0))
        preResult = firstOperand / secondOperand;
    else
        resultToShow = "E";

    if (resultToShow != "E")
    {
        result = preResult;
        resultToShow.setNum(result, 'f', 2);
        emit resultChanged(result);
    }
    emit resultChanged(resultToShow);

}
