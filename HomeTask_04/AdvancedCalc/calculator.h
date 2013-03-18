#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
signals:

    bool displayStringChanged(QString);
    bool invalidExpression();
    
private:
    Ui::Calculator *ui;
    double memory;
    QString displayString;
    double result;
    double currOperand;
    QString currOper;
    void getResult();
    double scanNumber(QString number);

private slots:
    void appendToDisplayString(QString toDisplay);
    void pushToDisplayString(QString toDisplay);

    void backSpace();
    void clearDisplayString();
    void clearExpression();
    void clearMemory();
    void clearAll();

    void setCurrOperand(double newOperand);
    void setCurrOper(QString newOper);
    void setResult(double res);
    void operButtonPressed(QString operation);

    void memoryAdd();
    void memoryDec();
    void memoryRead();

};

#endif // CALCULATOR_H
