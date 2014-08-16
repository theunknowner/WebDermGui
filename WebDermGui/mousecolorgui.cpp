#include "mousecolorgui.h"
#include "ui_mousecolorgui.h"

MouseColorGui::MouseColorGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseColorGui)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(pushButton_MouseColor()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closeProgram()));
}

MouseColorGui::~MouseColorGui()
{
    delete ui;
}

void MouseColorGui::pushButton_MouseColor() {
    String newImagePath = ui->lineEditPath->text().toStdString();
    String oldImagePath = "";
    if(newImagePath.length()>0) {
        Mat img, img2, mask;
        img = imread(newImagePath);
        if(!img.empty()==true && newImagePath!=oldImagePath) {
            oldImagePath = newImagePath;
            runResizeImage(newImagePath,Size(700,700),0);
            if(ui->checkBoxGetSkin->isChecked()) getSkin(img,mask);
            img.copyTo(img2,mask);
            Mouse::mouseColor(img2);
            img.release(); img2.release(); mask.release();
            destroyAllWindows();
        }
        else {
            QMessageBox * qBox = new QMessageBox(this);
            qBox->show();
            qBox->setText("File not found!");
        }
    }
}

void MouseColorGui::closeProgram() {
    destroyAllWindows();
}
