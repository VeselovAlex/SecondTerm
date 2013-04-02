#include "Command.h"
#include <iostream>

char Command::source()
{
    return sourceField;
}

QString Command::commandText()
{
    return commandTextField;
}

int Command::port()
{
    return portField;
}

int Command::parameter()
{
    return parameterField;
}

void Command::inputCommand()
{
    std::cin >> sourceField >> commandTextField >> portField >> parameterField;
}
