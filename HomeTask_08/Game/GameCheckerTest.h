#ifndef GAMECHECKERTEST_H
#define GAMECHECKERTEST_H
#include <QtTest/QTest>
#include "GameChecker.h"


class GameCheckerTest: public QObject
{
    Q_OBJECT
public:
    explicit GameCheckerTest(QObject* parent = 0) : QObject(parent){}
private slots:
    void testCrossWinsInRow()
    {
        GameChecker test;
        test.playersTurn(GameButton::crossToken, 0, 0);
        test.playersTurn(GameButton::crossToken, 0, 1);
        QVERIFY(!test.playersTurn(GameButton::crossToken, 0, 2));
    }
    void testCircleWinsInRow()
    {
        GameChecker test;
        test.playersTurn(GameButton::circleToken, 0, 0);
        test.playersTurn(GameButton::circleToken, 0, 1);
        QVERIFY(!test.playersTurn(GameButton::circleToken, 0, 2));
    }
    void testCrossWinsInCol()
    {
        GameChecker test;
        test.playersTurn(GameButton::crossToken, 0, 0);
        test.playersTurn(GameButton::crossToken, 1, 0);
        QVERIFY(!test.playersTurn(GameButton::crossToken, 2, 0));
    }
    void testCrossWinsInMain()
    {
        GameChecker test;
        test.playersTurn(GameButton::crossToken, 0, 0);
        test.playersTurn(GameButton::crossToken, 1, 1);
        QVERIFY(!test.playersTurn(GameButton::crossToken, 2, 2));
    }
    void testCrossWinsInSMain()
    {
        GameChecker test;
        test.playersTurn(GameButton::crossToken, 0, 2);
        test.playersTurn(GameButton::crossToken, 1, 1);
        QVERIFY(!test.playersTurn(GameButton::crossToken, 2, 0));
    }
};

#endif // GAMECHECKERTEST_H
