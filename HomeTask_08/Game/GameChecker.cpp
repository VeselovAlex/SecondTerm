#include "GameChecker.h"

GameChecker::GameChecker(QObject *parent) :
    QObject(parent)
{
    for (int i = 0; i < 8; i++)
        combs[i] = 0;
}


bool GameChecker::playersTurn(GameButton::Token token, int row, int col)
{
    combs[row] += token;
    combs[3 + col] += token;
    if (row == col)
        combs[6] += token;
    if ((row + col) == 2)
        combs[7] += token;

    if ((combs[row] == 3) || (combs[3 + col] == 3) || (combs[6] == 3) || (combs[7] == 3))
    {
        emit winner(GameButton::crossToken);
        emit gameEnd(false);
        return false;
    }
    if ((combs[row] == -3) || (combs[3 + col] == -3) || (combs[6] == -3) || (combs[7] == -3))
    {
        emit winner(GameButton::circleToken);
        emit gameEnd(false);
        return false;
    }
    return true;
}

