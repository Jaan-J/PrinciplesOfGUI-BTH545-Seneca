#include "mainwindow.h"
#include "toolbarbuttons.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *mainWindow = new QWidget;

    toolbarButtons generateButtons;

    QGridLayout* gridLayout = generateButtons.createHorizontalLayout();
    mainWindow->setLayout(gridLayout);
    mainWindow->show();
}

