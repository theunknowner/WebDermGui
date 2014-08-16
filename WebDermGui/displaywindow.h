#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include "global.h"
#include "qevent.h"
#include "Histogram/histogram.h"
#include "histogramdialog.h"
#include <QGraphicsView>
#include <QLabel>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = 0);
    ~DisplayWindow();
    bool eventFilter(QObject *obj, QEvent *event);
    void showImage(Mat img);
    void outputImage(Mat img);

public slots:
    void showHistogram();
    void changeImageContrast();
    void changeImageLuminance();
    void closeProgram();

private:
    Ui::DisplayWindow *ui;
    void setupStatusBar();
};

#endif // DISPLAYWINDOW_H
