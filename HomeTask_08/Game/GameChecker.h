#ifndef GAMECHECKER_H
#define GAMECHECKER_H

#include <QObject>
#include <QDebug>
#include "GameButton.h"



class GameChecker : public QObject
{
    Q_OBJECT
public:
    explicit GameChecker(QObject *parent = 0);
    
signals:
    bool gameEnd(bool);
    bool winner(GameButton::Token);
public slots:
    bool playersTurn(GameButton::Token token,int row, int col);
private:
    int combs[8];
    bool checkEnd();
};

#endif // GAMECHECKER_H
