#include "GameField.h"
#include <QAbstractButton>
#include <QIcon>
#include <QImage>
#include <QApplication>
#include "GameCheckerTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameField w;

    w.show();
    return a.exec();
    /*
    GameCheckerTest test;
    QTest::qExec(&test);
    return 0;
    */
}
