/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *clearLayout;
    QPushButton *cBackSpaceButton;
    QPushButton *cClearButton;
    QPushButton *cCEButton;
    QPushButton *cACButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *numberLayout;
    QPushButton *n8Button;
    QPushButton *n7Button;
    QPushButton *n9Button;
    QPushButton *n4Button;
    QPushButton *n5Button;
    QPushButton *n6Button;
    QPushButton *nDotButton;
    QPushButton *n1Button;
    QPushButton *n2Button;
    QPushButton *n3Button;
    QPushButton *n0Button;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *operatorLayout;
    QPushButton *oMultButton;
    QPushButton *oDivButton;
    QPushButton *oMinusButton;
    QPushButton *oEqButton;
    QPushButton *oPlusButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *memoryLayout;
    QPushButton *mPlusButton;
    QPushButton *mMinusButton;
    QPushButton *mReadButton;
    QPushButton *mClearButton;

    void setupUi(QWidget *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QStringLiteral("Calculator"));
        Calculator->resize(646, 357);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setWindowOpacity(0.9);
        verticalLayout = new QVBoxLayout(Calculator);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(Calculator);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font;
        font.setPointSize(16);
        lineEdit->setFont(font);
        lineEdit->setMaxLength(16);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        clearLayout = new QVBoxLayout();
        clearLayout->setSpacing(6);
        clearLayout->setObjectName(QStringLiteral("clearLayout"));
        clearLayout->setSizeConstraint(QLayout::SetFixedSize);
        cBackSpaceButton = new QPushButton(Calculator);
        cBackSpaceButton->setObjectName(QStringLiteral("cBackSpaceButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cBackSpaceButton->sizePolicy().hasHeightForWidth());
        cBackSpaceButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(16);
        cBackSpaceButton->setFont(font1);

        clearLayout->addWidget(cBackSpaceButton);

        cClearButton = new QPushButton(Calculator);
        cClearButton->setObjectName(QStringLiteral("cClearButton"));
        sizePolicy1.setHeightForWidth(cClearButton->sizePolicy().hasHeightForWidth());
        cClearButton->setSizePolicy(sizePolicy1);
        cClearButton->setFont(font1);

        clearLayout->addWidget(cClearButton);

        cCEButton = new QPushButton(Calculator);
        cCEButton->setObjectName(QStringLiteral("cCEButton"));
        sizePolicy1.setHeightForWidth(cCEButton->sizePolicy().hasHeightForWidth());
        cCEButton->setSizePolicy(sizePolicy1);
        cCEButton->setFont(font1);

        clearLayout->addWidget(cCEButton);

        cACButton = new QPushButton(Calculator);
        cACButton->setObjectName(QStringLiteral("cACButton"));
        sizePolicy1.setHeightForWidth(cACButton->sizePolicy().hasHeightForWidth());
        cACButton->setSizePolicy(sizePolicy1);
        cACButton->setFont(font1);

        clearLayout->addWidget(cACButton);


        horizontalLayout->addLayout(clearLayout);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        numberLayout = new QGridLayout();
        numberLayout->setSpacing(6);
        numberLayout->setObjectName(QStringLiteral("numberLayout"));
        numberLayout->setSizeConstraint(QLayout::SetFixedSize);
        n8Button = new QPushButton(Calculator);
        n8Button->setObjectName(QStringLiteral("n8Button"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(n8Button->sizePolicy().hasHeightForWidth());
        n8Button->setSizePolicy(sizePolicy2);
        n8Button->setFont(font1);

        numberLayout->addWidget(n8Button, 0, 1, 1, 1);

        n7Button = new QPushButton(Calculator);
        n7Button->setObjectName(QStringLiteral("n7Button"));
        sizePolicy2.setHeightForWidth(n7Button->sizePolicy().hasHeightForWidth());
        n7Button->setSizePolicy(sizePolicy2);
        n7Button->setFont(font1);

        numberLayout->addWidget(n7Button, 0, 0, 1, 1);

        n9Button = new QPushButton(Calculator);
        n9Button->setObjectName(QStringLiteral("n9Button"));
        sizePolicy2.setHeightForWidth(n9Button->sizePolicy().hasHeightForWidth());
        n9Button->setSizePolicy(sizePolicy2);
        n9Button->setFont(font1);

        numberLayout->addWidget(n9Button, 0, 2, 1, 1);

        n4Button = new QPushButton(Calculator);
        n4Button->setObjectName(QStringLiteral("n4Button"));
        sizePolicy2.setHeightForWidth(n4Button->sizePolicy().hasHeightForWidth());
        n4Button->setSizePolicy(sizePolicy2);
        n4Button->setFont(font1);

        numberLayout->addWidget(n4Button, 1, 0, 1, 1);

        n5Button = new QPushButton(Calculator);
        n5Button->setObjectName(QStringLiteral("n5Button"));
        sizePolicy2.setHeightForWidth(n5Button->sizePolicy().hasHeightForWidth());
        n5Button->setSizePolicy(sizePolicy2);
        n5Button->setFont(font1);

        numberLayout->addWidget(n5Button, 1, 1, 1, 1);

        n6Button = new QPushButton(Calculator);
        n6Button->setObjectName(QStringLiteral("n6Button"));
        sizePolicy2.setHeightForWidth(n6Button->sizePolicy().hasHeightForWidth());
        n6Button->setSizePolicy(sizePolicy2);
        n6Button->setFont(font1);

        numberLayout->addWidget(n6Button, 1, 2, 1, 1);

        nDotButton = new QPushButton(Calculator);
        nDotButton->setObjectName(QStringLiteral("nDotButton"));
        sizePolicy2.setHeightForWidth(nDotButton->sizePolicy().hasHeightForWidth());
        nDotButton->setSizePolicy(sizePolicy2);
        nDotButton->setFont(font1);

        numberLayout->addWidget(nDotButton, 3, 2, 1, 1);

        n1Button = new QPushButton(Calculator);
        n1Button->setObjectName(QStringLiteral("n1Button"));
        sizePolicy2.setHeightForWidth(n1Button->sizePolicy().hasHeightForWidth());
        n1Button->setSizePolicy(sizePolicy2);
        n1Button->setFont(font1);

        numberLayout->addWidget(n1Button, 2, 0, 1, 1);

        n2Button = new QPushButton(Calculator);
        n2Button->setObjectName(QStringLiteral("n2Button"));
        sizePolicy2.setHeightForWidth(n2Button->sizePolicy().hasHeightForWidth());
        n2Button->setSizePolicy(sizePolicy2);
        n2Button->setFont(font1);

        numberLayout->addWidget(n2Button, 2, 1, 1, 1);

        n3Button = new QPushButton(Calculator);
        n3Button->setObjectName(QStringLiteral("n3Button"));
        sizePolicy2.setHeightForWidth(n3Button->sizePolicy().hasHeightForWidth());
        n3Button->setSizePolicy(sizePolicy2);
        n3Button->setFont(font1);

        numberLayout->addWidget(n3Button, 2, 2, 1, 1);

        n0Button = new QPushButton(Calculator);
        n0Button->setObjectName(QStringLiteral("n0Button"));
        sizePolicy1.setHeightForWidth(n0Button->sizePolicy().hasHeightForWidth());
        n0Button->setSizePolicy(sizePolicy1);
        n0Button->setFont(font1);

        numberLayout->addWidget(n0Button, 3, 0, 1, 2);


        horizontalLayout->addLayout(numberLayout);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        operatorLayout = new QGridLayout();
        operatorLayout->setSpacing(6);
        operatorLayout->setObjectName(QStringLiteral("operatorLayout"));
        oMultButton = new QPushButton(Calculator);
        oMultButton->setObjectName(QStringLiteral("oMultButton"));
        sizePolicy1.setHeightForWidth(oMultButton->sizePolicy().hasHeightForWidth());
        oMultButton->setSizePolicy(sizePolicy1);
        oMultButton->setFont(font1);

        operatorLayout->addWidget(oMultButton, 0, 0, 1, 1);

        oDivButton = new QPushButton(Calculator);
        oDivButton->setObjectName(QStringLiteral("oDivButton"));
        sizePolicy1.setHeightForWidth(oDivButton->sizePolicy().hasHeightForWidth());
        oDivButton->setSizePolicy(sizePolicy1);
        oDivButton->setFont(font1);

        operatorLayout->addWidget(oDivButton, 0, 1, 1, 1);

        oMinusButton = new QPushButton(Calculator);
        oMinusButton->setObjectName(QStringLiteral("oMinusButton"));
        sizePolicy1.setHeightForWidth(oMinusButton->sizePolicy().hasHeightForWidth());
        oMinusButton->setSizePolicy(sizePolicy1);
        oMinusButton->setFont(font1);

        operatorLayout->addWidget(oMinusButton, 1, 1, 1, 1);

        oEqButton = new QPushButton(Calculator);
        oEqButton->setObjectName(QStringLiteral("oEqButton"));
        sizePolicy1.setHeightForWidth(oEqButton->sizePolicy().hasHeightForWidth());
        oEqButton->setSizePolicy(sizePolicy1);
        oEqButton->setFont(font1);

        operatorLayout->addWidget(oEqButton, 2, 1, 1, 1);

        oPlusButton = new QPushButton(Calculator);
        oPlusButton->setObjectName(QStringLiteral("oPlusButton"));
        sizePolicy1.setHeightForWidth(oPlusButton->sizePolicy().hasHeightForWidth());
        oPlusButton->setSizePolicy(sizePolicy1);
        oPlusButton->setFont(font1);

        operatorLayout->addWidget(oPlusButton, 1, 0, 2, 1);


        horizontalLayout->addLayout(operatorLayout);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        memoryLayout = new QVBoxLayout();
        memoryLayout->setSpacing(6);
        memoryLayout->setObjectName(QStringLiteral("memoryLayout"));
        memoryLayout->setSizeConstraint(QLayout::SetFixedSize);
        mPlusButton = new QPushButton(Calculator);
        mPlusButton->setObjectName(QStringLiteral("mPlusButton"));
        sizePolicy1.setHeightForWidth(mPlusButton->sizePolicy().hasHeightForWidth());
        mPlusButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        mPlusButton->setFont(font2);

        memoryLayout->addWidget(mPlusButton);

        mMinusButton = new QPushButton(Calculator);
        mMinusButton->setObjectName(QStringLiteral("mMinusButton"));
        sizePolicy1.setHeightForWidth(mMinusButton->sizePolicy().hasHeightForWidth());
        mMinusButton->setSizePolicy(sizePolicy1);
        mMinusButton->setFont(font2);

        memoryLayout->addWidget(mMinusButton);

        mReadButton = new QPushButton(Calculator);
        mReadButton->setObjectName(QStringLiteral("mReadButton"));
        sizePolicy1.setHeightForWidth(mReadButton->sizePolicy().hasHeightForWidth());
        mReadButton->setSizePolicy(sizePolicy1);
        mReadButton->setFont(font2);

        memoryLayout->addWidget(mReadButton);

        mClearButton = new QPushButton(Calculator);
        mClearButton->setObjectName(QStringLiteral("mClearButton"));
        sizePolicy1.setHeightForWidth(mClearButton->sizePolicy().hasHeightForWidth());
        mClearButton->setSizePolicy(sizePolicy1);
        mClearButton->setFont(font2);

        memoryLayout->addWidget(mClearButton);


        horizontalLayout->addLayout(memoryLayout);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QWidget *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", 0));
        lineEdit->setText(QApplication::translate("Calculator", "0", 0));
        cBackSpaceButton->setText(QApplication::translate("Calculator", "\342\206\220", 0));
        cClearButton->setText(QApplication::translate("Calculator", "C", 0));
        cCEButton->setText(QApplication::translate("Calculator", "CE", 0));
        cACButton->setText(QApplication::translate("Calculator", "AC", 0));
        n8Button->setText(QApplication::translate("Calculator", "8", 0));
        n7Button->setText(QApplication::translate("Calculator", "7", 0));
        n9Button->setText(QApplication::translate("Calculator", "9", 0));
        n4Button->setText(QApplication::translate("Calculator", "4", 0));
        n5Button->setText(QApplication::translate("Calculator", "5", 0));
        n6Button->setText(QApplication::translate("Calculator", "6", 0));
        nDotButton->setText(QApplication::translate("Calculator", ".", 0));
        n1Button->setText(QApplication::translate("Calculator", "1", 0));
        n2Button->setText(QApplication::translate("Calculator", "2", 0));
        n3Button->setText(QApplication::translate("Calculator", "3", 0));
        n0Button->setText(QApplication::translate("Calculator", "0", 0));
        oMultButton->setText(QApplication::translate("Calculator", "*", 0));
        oDivButton->setText(QApplication::translate("Calculator", "/", 0));
        oMinusButton->setText(QApplication::translate("Calculator", "-", 0));
        oEqButton->setText(QApplication::translate("Calculator", "=", 0));
        oPlusButton->setText(QApplication::translate("Calculator", "+", 0));
        mPlusButton->setText(QApplication::translate("Calculator", "M+", 0));
        mMinusButton->setText(QApplication::translate("Calculator", "M-", 0));
        mReadButton->setText(QApplication::translate("Calculator", "MR", 0));
        mClearButton->setText(QApplication::translate("Calculator", "MC", 0));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
