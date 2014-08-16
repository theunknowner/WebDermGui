#include "displaywindow.h"
#include "ui_displaywindow.h"

Mat origImg; // copy of original image untouched
Mat img2,tempImg; // tempImg gets cvtColor from BGR2RGB
QLabel *posLabel;
QLabel *rgbLabel;
QLabel *hslLabel;
QLabel *relLumLabel;
QGraphicsScene *gScene;
QImage qimg;
HistogramDialog* HD;

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
    this->setupStatusBar();
    connect(ui->checkBoxHistogram, SIGNAL(toggled(bool)), this, SLOT(showHistogram()));
    connect(ui->lineEditAlpha, SIGNAL(returnPressed()), this, SLOT(changeImageContrast()));
    connect(ui->lineEditBeta, SIGNAL(returnPressed()), this, SLOT(changeImageContrast()));
    connect(ui->lineEditLum, SIGNAL(returnPressed()), this, SLOT(changeImageLuminance()));
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

void DisplayWindow::setupStatusBar() {
    posLabel = new QLabel(statusBar());
    rgbLabel = new QLabel(statusBar());
    hslLabel = new QLabel(statusBar());
    relLumLabel = new QLabel(statusBar());
    ui->statusbar->addWidget(posLabel);
    ui->statusbar->addWidget(rgbLabel);
    ui->statusbar->addWidget(hslLabel);
    ui->statusbar->addWidget(relLumLabel);
}

/** display mouse position in status bar **/
bool DisplayWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove) {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    Point pt;
    pt.x = mouseEvent->pos().x();
    pt.y = mouseEvent->pos().y();
    rgb rgb;
    int r = img2.at<Vec3b>(pt.y,pt.x)[2];
    int g = img2.at<Vec3b>(pt.y,pt.x)[1];
    int b = img2.at<Vec3b>(pt.y,pt.x)[0];
    double relLum = round(rgb.calcPerceivedBrightness(r,g,b));
    hsl hsl;
    double *HSL = hsl.rgb2hsl(r,g,b);
    HSL[1] = roundDecimal(HSL[1],2);
    HSL[2] = roundDecimal(HSL[2],2);
    posLabel->setText(QString("(%1,%2)").arg(pt.x).arg(pt.y));
    rgbLabel->setText(QString("rgb(%1,%2,%3)").arg(r).arg(g).arg(b));
    hslLabel->setText(QString("hsl(%1,%2,%3)").arg(HSL[0]).arg(HSL[1]).arg(HSL[2]));
    relLumLabel->setText(QString("Brightness:%1").arg(relLum));
    //ui->statusbar->showMessage(QString("(%1,%2)").arg(pt.x).arg(pt.y));
    //ui->statusbar->showMessage(QString("(%3,%4,%5)").arg(r).arg(g).arg(b));
  }

  return false;
}

QImage convertMat2QImage(Mat img) {
    cvtColor(img,tempImg,CV_BGR2RGB);
    QImage qImg = QImage((uchar*) tempImg.data, tempImg.cols, tempImg.rows, tempImg.step, QImage::Format_RGB888);
    return qImg;
}

/** display image with mouse tracking **/
void DisplayWindow::showImage(Mat img) {
    qimg = convertMat2QImage(img);
    QPixmap qpix= QPixmap::fromImage(qimg);
    static QGraphicsScene *scene = new QGraphicsScene(this);
    gScene = scene;
    scene->addPixmap(qpix);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->viewport()->setMouseTracking(true);
    ui->graphicsView->viewport()->installEventFilter(this);
}

void DisplayWindow::outputImage(Mat img) {
    img2 = img.clone();
    origImg = img.clone();
    showImage(img2);
}

void DisplayWindow::showHistogram() {
    if(!img2.empty()) {
        Histogram hist;
        Mat histImg = hist.calcHistogram(img2);
        //static int flag=0;
        static HistogramDialog* hd = new HistogramDialog();
        HD = hd;
        if(ui->checkBoxHistogram->isChecked()==true) {
            hd->show();
            //if(flag==0) {
                hd->showImage(histImg);
                //flag=1;
            //}
        }
        else if(ui->checkBoxHistogram->isChecked()==false) {
            hd->hide();
        }
    }
}

void DisplayWindow::changeImageContrast() {
    Color c;
    double alpha = ui->lineEditAlpha->text().toDouble();
    double beta = ui->lineEditBeta->text().toDouble();
    img2 = c.changeImageContrast(origImg,alpha,beta);
    showImage(img2);
    if(ui->checkBoxHistogram->isChecked()==true) {
        showHistogram();
    }
}

void DisplayWindow::changeImageLuminance() {
    Color c;
    double lum = ui->lineEditLum->text().toDouble();
    img2 = c.changeImageBrightness(img2,lum);
    showImage(img2);
    if(ui->checkBoxHistogram->isChecked()==true) {
        showHistogram();
    }
}

void DisplayWindow::closeProgram() {
    delete HD;
    delete posLabel;
    delete rgbLabel;
    delete hslLabel;
    delete gScene;
}
