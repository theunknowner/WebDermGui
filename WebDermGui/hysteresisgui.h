#ifndef HYSTERESISGUI_H
#define HYSTERESISGUI_H

#include <QMainWindow>
#include "functions.h"
#include "hysteresis/hysteresis.h"
#include "rgb/rgb.h"
#include "hsl/hsl.h"

namespace Ui {
class HysteresisGui;
}

class HysteresisGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit HysteresisGui(QWidget *parent = 0);
    ~HysteresisGui();

public slots:
    void pushButton_Hysteresis();

private:
    Ui::HysteresisGui *ui;
};

#endif // HYSTERESISGUI_H
