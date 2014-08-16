#include "hysteresisgui.h"
#include "ui_hysteresisgui.h"

HysteresisGui::HysteresisGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HysteresisGui)
{
    ui->setupUi(this);
    connect(ui->lineEditPath, SIGNAL(returnPressed()), this, SLOT(pushButton_Hysteresis()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(pushButton_Hysteresis()));
}

HysteresisGui::~HysteresisGui()
{
    delete ui;
}

void HysteresisGui::pushButton_Hysteresis() {

}
