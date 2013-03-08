#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);
private:
    int firstOperand;
    int secondOperand;
    QString operation;
    double result;
    QString resultToShow;
    
signals:
    bool firstOperandChanged(int value);
    bool secondOperandChanged(int value);
    bool operationChanged(QString newOperation);
    bool resultChanged(double);
    bool resultChanged(QString);
    
public slots:
    void changeFirstOperand(int value);
    void changeSecondOperand(int value);
    void changeOperation(QString newOperation);
    void getResult();
    
};

#endif // CALCULATOR_H
