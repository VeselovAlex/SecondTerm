#ifndef COMMAND_H
#define COMMAND_H
#include <QString>

class Command
{
public:
    Command(char source = 0, const QString& commandText = "",
            int portNum = 0, int param = 0) :
        sourceField(source),
        commandTextField(commandText),
        portField (portNum),
        parameterField(param) {}

    char source();
    QString commandText();
    int port();
    int parameter();
    void inputCommand();

private:
    char sourceField;
    QString commandTextField;
    int portField;
    int parameterField;
};

#endif // COMMAND_H
