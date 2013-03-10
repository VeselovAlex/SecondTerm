#include "calculator.h"
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

    QSignalMapper *operatorPressed = new QSignalMapper;

    QObject::connect(ui->oDivButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oMultButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oPlusButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));
    QObject::connect(ui->oMinusButton, SIGNAL(clicked()), operatorPressed, SLOT(map()));

    operatorPressed->setMapping(ui->oDivButton, "/");
    operatorPressed->setMapping(ui->oMultButton, "*");
    operatorPressed->setMapping(ui->oPlusButton, "+");
    operatorPressed->setMapping(ui->oMinusButton, "-");


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

void Calculator::clearDisplayString()
{
    displayString = "";
    emit displayStringChanged("");
}

void Calculator::clearExpression()
{
    clearDisplayString();
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

void Calculator::getResult()
{
    if (currOper == "+")
        result = result + currOperand;
    if (currOper == "-")
        result = result + currOperand;
    if (currOper == "*")
        result = result + currOperand;
    if ((currOper == "/") && (currOperand != 0))
        result = result + currOperand;
    else
        emit invalidExpression();

}

void Calculator::operatorChanged(QString newOperator)
{
    double operand = displayString.toDouble();
    if (currOper == "")
        result = operand;
    else
    {
        currOperand = operand;
        getResult();
    }
    currOper = newOperator;
}
