#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include <QIcon>
#include <QImage>
#include <QSignalMapper>

class GameButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameButton(const QSize& size, QWidget *parent = 0);
    enum Token
    {
        crossToken = 1,
        circleToken = -1,
        noToken = 0
    };

signals:
    bool currTurn(const QIcon&);
    bool currTurn(int);
    bool currTokenChanged(GameButton::Token);
    bool currCoordinates(GameButton::Token, int, int);
public slots:
    void setCoordinates(int x, int y);
    void setCoordinates(int* coords);
private slots:
    void nextTurn();
    void setCurrToken(GameButton::Token token);

private:
    Token currToken;
    QIcon crossIcon;
    QIcon circleIcon;
    int coordinates[2];
};


#endif // GAMEBUTTON_H
