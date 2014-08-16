#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(pushShowImageButton()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closeProgram()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(pushShowImageButton()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

/** display mouse position in status bar **/
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    ui->statusBar->showMessage(QString("(%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
  }

  return false;
}

Mat img;
DisplayWindow* DW;

/** displays image when "Show" button is clicked **/
void MainWindow::pushShowImageButton() {
    String newImagePath = ui->lineEdit->text().toStdString();
    String oldImagePath = "";
    if(newImagePath.length()>0) {
        img = imread(newImagePath);
        if(!img.empty()==true && newImagePath!=oldImagePath) {
            oldImagePath = newImagePath;
            static DisplayWindow* dw = new DisplayWindow();
            DW = dw;
            DW->show();
            DW->outputImage(img);
        }
        else {
            QMessageBox * qBox = new QMessageBox(this);
            qBox->show();
            qBox->setText("File not found!");
        }
    }
}

void MainWindow::closeProgram() {
    DW->closeProgram();
    delete DW;
}
