#include "RobotGUI.h"
#include "ui_RobotGUI.h"

RobotGUI::RobotGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotGUI)
{
    ui->setupUi(this);
}

RobotGUI::~RobotGUI()
{
    delete ui;
}
