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

private slots:
    void appendToDisplayString(QString toDisplay);
    void pushToDisplayString(QString toDisplay);

    void clearDisplayString();
    void clearExpression();
    void clearMemory();
    void clearAll();

    void operatorChanged(QString newOperator);

};

#endif // CALCULATOR_H
