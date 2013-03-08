#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    QFont calcFont = QFont("Times", 14);
    Calculator *calc = new Calculator;

    QSpinBox *firstOperand = new QSpinBox;
    firstOperand->setFont(calcFont);
    firstOperand->setAlignment(Qt::AlignRight);
    firstOperand->setRange(INT_MIN, INT_MAX);
    QObject::connect(firstOperand, SIGNAL(valueChanged(int)),
                     calc, SLOT(changeFirstOperand(int)));
    emit firstOperand->valueChanged(0);

    QSpinBox *secondOperand = new QSpinBox;
    secondOperand->setFont(calcFont);
    secondOperand->setAlignment(Qt::AlignRight);
    secondOperand->setRange(INT_MIN, INT_MAX);
    QObject::connect(secondOperand, SIGNAL(valueChanged(int)),
                     calc, SLOT(changeSecondOperand(int)));
    emit secondOperand->valueChanged(0);

    QComboBox *operation = new QComboBox;
    operation->setFont(calcFont);
    operation->addItem("+");
    operation->addItem("-");
    operation->addItem("*");
    operation->addItem("/");
    QObject::connect(operation, SIGNAL(currentTextChanged(QString)),
                     calc, SLOT(changeOperation(QString)));
    emit operation->currentTextChanged("+");

    QLabel *equalSign = new QLabel;
    equalSign->setText(" = ");
    equalSign->setFont(calcFont);

    QLineEdit *resultBox = new QLineEdit;
    resultBox->setFont(calcFont);
    resultBox->setAlignment(Qt::AlignRight);
    resultBox->setReadOnly(true);
    resultBox->setText("0");
    QObject::connect(calc, SIGNAL(resultChanged(QString)),
                     resultBox, SLOT(setText(QString)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(firstOperand);
    layout->addWidget(operation);
    layout->addWidget(secondOperand);
    layout->addWidget(equalSign);
    layout->addWidget(resultBox);

    window->setLayout(layout);
    window->setWindowTitle("Простой калькулятор");
    window->show();
    
    return a.exec();
}
