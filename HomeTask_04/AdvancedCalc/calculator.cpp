#include "calculator.h"
#include "calc/SimpleCalculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator), memory(0), result(0), currOperand(0), currOper("")
{
    ui->setupUi(this);

    QSignalMapper *numberPressed = new QSignalMapper(this);

    {
    QObject::connect(ui->n0Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n1Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n2Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n3Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n4Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n5Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n6Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n7Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n8Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->n9Button, SIGNAL(clicked()), numberPressed, SLOT(map()));
    QObject::connect(ui->nDotButton, SIGNAL(clicked()), numberPressed, SLOT(map()));
    }

    {
    numberPressed->setMapping(ui->n0Button, "0");
    numberPressed->setMapping(ui->n1Button, "1");
    numberPressed->setMapping(ui->n2Button, "2");
    numberPressed->setMapping(ui->n3Button, "3");
    numberPressed->setMapping(ui->n4Button, "4");
    numberPressed->setMapping(ui->n5Button, "5");
    numberPressed->setMapping(ui->n6Button, "6");
    numberPressed->setMapping(ui->n7Button, "7");
    numberPressed->setMapping(ui->n8Button, "8");
    numberPressed->setMapping(ui->n9Button, "9");
    numberPressed->setMapping(ui->nDotButton, ".");
    }
    QObject::connect(numberPressed, SIGNAL(mapped(QString)), this, SLOT(appendToDisplayString(QString)));
    QObject::connect(this, SIGNAL(displayStringChanged(QString)), ui->lineEdit, SLOT(setText(QString)));

    QObject::connect(ui->cClearButton, SIGNAL(clicked()), this, SLOT(clearDisplayString()));
    QObject::connect(ui->cCEButton, SIGNAL(clicked()), this, SLOT(clearExpression()));
    QObject::connect(ui->cACButton, SIGNAL(clicked()), this, SLOT(clearAll()));
    QObject::connect(ui->cBackSpaceButton, SIGNAL(clicked()), this, SLOT(backSpace()));

    QSignalMapper *operatorPressed = new QSignalMapper;

    QObject::connect(ui->oDivButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oMultButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oPlusButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oMinusButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oEqButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));

    operatorPressed->setMapping(ui->oDivButton, "/");
    operatorPressed->setMapping(ui->oMultButton, "*");
    operatorPressed->setMapping(ui->oPlusButton, "+");
    operatorPressed->setMapping(ui->oMinusButton, "-");
    operatorPressed->setMapping(ui->oEqButton, "=");

    QObject::connect(operatorPressed, SIGNAL(mapped(QString)), this, SLOT(operButtonPressed(QString)));

    QObject::connect(ui->nDotButton, SIGNAL(clicked(bool)), ui->nDotButton, SLOT(setEnabled(bool)));

    QObject::connect(ui->mClearButton, SIGNAL(clicked()), this, SLOT(clearMemory()));
    QObject::connect(ui->mReadButton, SIGNAL(clicked()), this, SLOT(memoryRead()));
    QObject::connect(ui->mPlusButton, SIGNAL(clicked()), this, SLOT(memoryAdd()));
    QObject::connect(ui->mMinusButton, SIGNAL(clicked()), this, SLOT(memoryDec()));

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::appendToDisplayString(QString toDisplay)
{
    displayString += toDisplay;
    emit displayStringChanged(displayString);
}

void Calculator::pushToDisplayString(QString toDisplay)
{
    displayString = toDisplay;
    emit displayStringChanged(displayString);
}

void Calculator::backSpace()
{
    if (displayString.isEmpty())
        return;
    if (displayString[displayString.size() - 1].cell() == '.')
        ui->nDotButton->setEnabled(true);
    displayString.remove(displayString.size() - 1, 1);
    emit displayStringChanged(displayString);
}

void Calculator::clearDisplayString()
{
    displayString = "";
    emit displayStringChanged("");
}

void Calculator::clearExpression()
{
    clearDisplayString();
    ui->oEqButton->setEnabled(true);
}

void Calculator::clearMemory()
{
    memory = 0;
}

void Calculator::clearAll()
{
    clearDisplayString();
    clearExpression();
    clearMemory();
}

void Calculator::setCurrOperand(double newOperand)
{
    currOperand = newOperand;
}

void Calculator::setCurrOper(QString newOper)
{
    currOper = newOper;
}

void Calculator::setResult(double res)
{
    result = res;
}

void Calculator::operButtonPressed(QString operation)
{
    currOperand = scanNumber(displayString);
    clearDisplayString();
    ui->nDotButton->setEnabled(true);

    if (currOper != "")
    {
        SimpleCalculator* simpleCalc = new SimpleCalculator();
        QObject::connect(simpleCalc, SIGNAL(resultChanged(double)),
                         this, SLOT(setResult(double)));
        simpleCalc->changeFirstOperand(result);
        simpleCalc->changeSecondOperand(currOperand);
        simpleCalc->changeOperation(currOper);
        simpleCalc->getResult();
        currOper = operation;
        delete simpleCalc;

    }
    else
    {
        result = currOperand;
        currOper = operation;
    }

    QString resultAsString;
    resultAsString.setNum(result, 'f', 2);
    ui->lineEdit->setText(resultAsString);

    if (currOper == "=")
    {
        currOper = "";
        currOperand = result;
        ui->oEqButton->setDisabled(true);
    }
}

void Calculator::memoryAdd()
{
    double toMemory = scanNumber(displayString);
    memory += toMemory;
}

void Calculator::memoryDec()
{
    double toMemory = scanNumber(displayString);
    memory -= toMemory;
}

void Calculator::memoryRead()
{
    QString memoryAsString;
    memoryAsString.setNum(memory, 'f', 2);
    displayString = memoryAsString;
    emit displayStringChanged(displayString);
}
double Calculator::scanNumber(QString number)
{
    return number.toDouble();
}


