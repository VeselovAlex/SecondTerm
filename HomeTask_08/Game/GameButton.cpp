#include "GameButton.h"

GameButton::GameButton(const QSize& size, QWidget *parent) :
    QPushButton(parent)
{
    crossIcon = QIcon(":/cross_icon.jpg");
    circleIcon = QIcon(":/circle_icon.png");
    this->setFixedSize(size);
    this->setIconSize(size);
    this->setFlat(true);
    connect (this, SIGNAL(clicked()), SLOT(nextTurn()));
}


void GameButton::nextTurn()
{
    if (currToken == crossToken)
    {
        this->setIcon(circleIcon);
        emit currTurn(circleIcon);
        currToken = circleToken;
    }
    else
    {
        this->setIcon(crossIcon);
        emit currTurn(crossIcon);
        currToken = crossToken;
    }
    this->setEnabled(false);
    emit currCoordinates(currToken, coordinates[0], coordinates[1]);
    emit currTurn(currToken);
    emit currTokenChanged(currToken);
}

void GameButton::setCurrToken(GameButton::Token token)
{
    currToken = token;
}

void GameButton::setCoordinates(int x, int y)
{
    coordinates[0] = x;
    coordinates[1] = y;
}

void GameButton::setCoordinates(int *coords)
{
    coordinates[0] = coords[0];
    coordinates[1] = coords[1];
}
