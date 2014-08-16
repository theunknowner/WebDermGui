#ifndef MOUSECOLORGUI_H
#define MOUSECOLORGUI_H

#include <QDialog>
#include <QMessageBox>
#include "global.h"
#include "Math/maths.h"
#include "run.h"
#include "skin/Skin.h"
#include "Mouse/mouse.h"

namespace Ui {
class MouseColorGui;
}

class MouseColorGui : public QDialog
{
    Q_OBJECT

public:
    explicit MouseColorGui(QWidget *parent = 0);
    ~MouseColorGui();

public slots:
    void pushButton_MouseColor();
    void closeProgram();

private:
    Ui::MouseColorGui *ui;
};

#endif // MOUSECOLORGUI_H
