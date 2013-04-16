#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QImage>

#include "GameChecker.h"

namespace Ui {
class GameField;
}

class GameField : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField();
signals:
    bool currTokenChanged(GameButton::Token);
public slots:
    void setCurrToken(GameButton::Token token);
    void setCurrTokenItemIcon(GameButton::Token token);
    void showWinner(GameButton::Token winnerToken);
    
private:
    Ui::GameField *ui;
    GameChecker checker;
    GameButton::Token currToken;
    GameButton* currTokenItem;
};

#endif // GAMEFIELD_H
