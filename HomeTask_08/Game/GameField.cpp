#include "GameField.h"
#include "ui_GameField.h"
#include <QDebug>

GameField::GameField(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameField)
{
    ui->setupUi(this);

    this->saveGeometry();
    QSize size;
    size.setHeight(128);
    size.setWidth(128);

    currTokenItem = new GameButton(size, this);
    ui->currTokenLayout->addWidget(currTokenItem);
    currTokenItem->setEnabled(false);
    currTokenItem->setIcon(QIcon(":/cross_icon.jpg"));
    currTokenItem->setFixedSize(64,64);
    currTokenItem->setIconSize(currTokenItem->size());
    connect(&checker, SIGNAL(gameEnd(bool)), currTokenItem, SLOT(setVisible(bool)));

    connect(this, SIGNAL(currTokenChanged(GameButton::Token)),
            this, SLOT(setCurrTokenItemIcon(GameButton::Token)));

    connect(&checker, SIGNAL(winner(GameButton::Token)), this, SLOT(showWinner(GameButton::Token)));



    for (int i = 0; i < 9; i++)
    {
        GameButton *button = new GameButton(size, this);
        ui->gridLayout->addWidget(button, i / 3, i % 3);
        connect(button, SIGNAL(currTokenChanged(GameButton::Token)),
                this, SLOT(setCurrToken(GameButton::Token)));
        connect(this, SIGNAL(currTokenChanged(GameButton::Token)),
                button, SLOT(setCurrToken(GameButton::Token)));
        button->setCoordinates(i / 3, i % 3);
        connect(button, SIGNAL(currCoordinates(GameButton::Token,int,int)), &checker, SLOT(playersTurn(GameButton::Token,int,int)));

        connect(&checker, SIGNAL(gameEnd(bool)), button, SLOT(setEnabled(bool)));
    }
}

GameField::~GameField()
{
    delete ui;
    delete currTokenItem;
}



void GameField::setCurrToken(GameButton::Token token)
{
    emit currTokenChanged(token);
}

void GameField::setCurrTokenItemIcon(GameButton::Token token)
{
    if (token == GameButton::crossToken)
        currTokenItem->setIcon(QIcon(":/circle_icon.png"));
    else
        currTokenItem->setIcon(QIcon(":/cross_icon.jpg"));
}

void GameField::showWinner(GameButton::Token winnerToken)
{
    ui->label->setGeometry(0, 400, 200, 64);
    if (winnerToken == GameButton::crossToken)
        ui->label->setText("Winner: Cross");
    else
        ui->label->setText("Winner: Circle");
}
