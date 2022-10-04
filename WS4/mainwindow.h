#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <iostream>
#include "QString"
#include "QGridLayout"
#include "QToolButton"
#include "QDir"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::vector <std::string> formattedButtonNames_;
    std::vector <std::string> buttonIconFileName;
    bool isConfigurationSaved_ = false;

public:
    MainWindow(QWidget *parent = nullptr);
    QString formatAndStoreNames(QString rawFileName);
    std::vector<std::string> fetchButtonNames(){return formattedButtonNames_;};
    QGridLayout *createHorizontalLayout();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
