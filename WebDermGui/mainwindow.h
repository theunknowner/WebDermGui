#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stdafx.h"
#include "qevent.h"
#include <QMessageBox>
#include "displaywindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void pushShowImageButton();
    void closeProgram();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
