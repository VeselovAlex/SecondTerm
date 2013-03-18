#pragma once

#include <QObject>

class SimpleCalculator : public QObject
{
    Q_OBJECT
public:
    explicit SimpleCalculator(QObject *parent = 0);
    double getRes();
private:
    double firstOperand;
    double secondOperand;
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
    void changeFirstOperand(double value);
    void changeSecondOperand(double value);
    void changeOperation(QString newOperation);
    void getResult();
    
};

