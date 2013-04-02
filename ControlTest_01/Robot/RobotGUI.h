#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QWidget>

namespace Ui {
class RobotGUI;
}

class RobotGUI : public QWidget
{
    Q_OBJECT
    
public:
    explicit RobotGUI(QWidget *parent = 0);
    ~RobotGUI();
    
private:
    Ui::RobotGUI *ui;
};

#endif // ROBOTGUI_H
