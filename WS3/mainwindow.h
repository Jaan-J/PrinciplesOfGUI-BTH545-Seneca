#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ResetBtn_clicked();

    void on_largePizzaOption_clicked(bool checked);

    void on_cancelBtn_clicked();

    void on_placeOrderBtn_clicked();

    void on_nameInput_textChanged();

    void on_streetInput_textChanged();


    void on_cityInput_textChanged();

    void on_postalCodeInput_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
