#include "histogramdialog.h"
#include "ui_histogramdialog.h"

HistogramDialog::HistogramDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistogramDialog)
{
    ui->setupUi(this);
}

HistogramDialog::~HistogramDialog()
{
    delete ui;
}

void HistogramDialog::showImage(Mat img) {
    QImage qimg((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    QPixmap qpix= QPixmap::fromImage(qimg);
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(qpix);
    ui->graphicsView->setScene(scene);
}
