#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->firstToppingSelection->setPlaceholderText("First Topping");
    ui->firstToppingSelection->addItem("Ham");
    ui->firstToppingSelection->addItem("Pepperoni");
    ui->firstToppingSelection->addItem("Green Pepper");
    ui->firstToppingSelection->addItem("Mushroom");
    ui->firstToppingSelection->addItem("Pineapple");
    ui->firstToppingSelection->addItem("Onion");
    ui->firstToppingSelection->addItem("Artichokes");
    ui->firstToppingSelection->addItem("Black Olives");
    ui->firstToppingSelection->addItem("Extra Cheese");

    ui->secondToppingSelection->setPlaceholderText("Second Topping");
    ui->secondToppingSelection->addItem("Ham");
    ui->secondToppingSelection->addItem("Pepperoni");
    ui->secondToppingSelection->addItem("Green Pepper");
    ui->secondToppingSelection->addItem("Mushroom");
    ui->secondToppingSelection->addItem("Pineapple");
    ui->secondToppingSelection->addItem("Onion");
    ui->secondToppingSelection->addItem("Artichokes");
    ui->secondToppingSelection->addItem("Black Olives");
    ui->secondToppingSelection->addItem("Extra Cheese");

    ui->lastToppingSelection->setPlaceholderText("Third Topping");
    ui->lastToppingSelection->addItem("Ham");
    ui->lastToppingSelection->addItem("Pepperoni");
    ui->lastToppingSelection->addItem("Green Pepper");
    ui->lastToppingSelection->addItem("Mushroom");
    ui->lastToppingSelection->addItem("Pineapple");
    ui->lastToppingSelection->addItem("Onion");
    ui->lastToppingSelection->addItem("Artichokes");
    ui->lastToppingSelection->addItem("Black Olives");
    ui->lastToppingSelection->addItem("Extra Cheese");

    ui->promptStreetError->hide();
    ui->promptStreetError->setStyleSheet("QLabel { color : red; }");

    ui->promptCityError->hide();
    ui->promptCityError->setStyleSheet("QLabel { color : red; }");

    ui->promptNameError->hide();
    ui->promptNameError->setStyleSheet("QLabel { color : red; }");

    ui->promptPostalError->hide();
    ui->promptPostalError->setStyleSheet("QLabel { color : red; }");

    connect(ui->largePizzaOption, &QRadioButton::toggled, this, &MainWindow::on_largePizzaOption_clicked);
    connect(ui->resetBtn, &QPushButton::clicked, this, &MainWindow::on_ResetBtn_clicked);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_ResetBtn_clicked(){
    ui->firstToppingSelection->setCurrentIndex(-1);
    ui->secondToppingSelection->setCurrentIndex(-1);
    ui->lastToppingSelection->setCurrentIndex(-1);

    ui ->largePizzaOption->setAutoExclusive(false);
    ui ->largePizzaOption->setChecked(false);
    ui ->largePizzaOption->setAutoExclusive(true);

    ui ->mediumPizzaOption->setAutoExclusive(false);
    ui ->mediumPizzaOption->setChecked(false);
    ui ->mediumPizzaOption->setAutoExclusive(true);

    ui ->smallPizzaOption->setAutoExclusive(false);
    ui ->smallPizzaOption->setChecked(false);
    ui ->smallPizzaOption->setAutoExclusive(true);
}


void MainWindow::on_largePizzaOption_clicked(bool checked){
    if(checked){
        ui->firstToppingSelection->removeItem(8);
        ui->secondToppingSelection->removeItem(8);
        ui->lastToppingSelection->removeItem(8);
        return;
    }
    ui->firstToppingSelection->insertItem(8, "Extra Cheese");
    ui->secondToppingSelection->insertItem(8, "Extra Cheese");
    ui->lastToppingSelection->insertItem(8, "Extra Cheese");
}


void MainWindow::on_cancelBtn_clicked(){
    QApplication::quit();
}


void MainWindow::on_placeOrderBtn_clicked(){
    QString firstTopping = ui->firstToppingSelection->currentText();
    QString secondTopping = ui->secondToppingSelection->currentText();
    QString lastTopping = ui->lastToppingSelection->currentText();
    QString streetAddress = ui->streetInput->toPlainText();
    QString city = ui->cityInput->toPlainText();
    QString postalCode = ui->postalCodeInput->toPlainText();
    QString aptNum = ui->AptEdit->toPlainText();
    QString customerName = ui->nameInput->toPlainText();

    QString promptFirstHalf = "Thank you " + customerName + ", you ordered a ";
    QString promptMiddle;
    QString promptSecondHalf = "to: " + streetAddress + ", " + city + ", " + postalCode + ".";
    if (!aptNum.isEmpty()){
        promptSecondHalf = " to: " + aptNum + ", " + streetAddress + ", " + city + ", " + postalCode + ".";
    }
    if(!firstTopping.isEmpty() && secondTopping.isEmpty() && lastTopping.isEmpty()){
        promptMiddle = "pizza with " + firstTopping;
    }else if(!firstTopping.isEmpty() && !secondTopping.isEmpty() && lastTopping.isEmpty()){
        promptMiddle = "pizza with " + firstTopping + " and " + secondTopping;
    }else if (!firstTopping.isEmpty() && !secondTopping.isEmpty() && !lastTopping.isEmpty()){
        promptMiddle = "pizza with " + firstTopping + ", " + secondTopping + ", and " + lastTopping;
    }else if (firstTopping.isEmpty() && !secondTopping.isEmpty() && !lastTopping.isEmpty()){
        promptMiddle = "pizza with " + secondTopping + " and " + lastTopping;
    }else if(!firstTopping.isEmpty() && secondTopping.isEmpty() && !lastTopping.isEmpty()){
        promptMiddle = "pizza with " + firstTopping + " and " + lastTopping;
    }else{
        promptMiddle = "plain pizza";
    }

    if (ui -> nameInput -> toPlainText().isEmpty()){
        ui -> nameInput -> setFocus();
    }else if (ui -> streetInput -> toPlainText().isEmpty()){
        ui -> streetInput -> setFocus();
    }else if (ui -> cityInput -> toPlainText().isEmpty()){
        ui -> cityInput -> setFocus();
    }else if (ui -> postalCodeInput -> toPlainText().isEmpty()){
        ui -> postalCodeInput -> setFocus();
    }else if (!ui->largePizzaOption->isChecked() && !ui->mediumPizzaOption->isChecked() && !ui->smallPizzaOption->isChecked()){
         QMessageBox::information(this, "Order", "Please Select Size");
    }else if (ui -> largePizzaOption -> isChecked()){
         QMessageBox::information(this, "Order", promptFirstHalf + "large " + promptMiddle + " "  + promptSecondHalf);
         QApplication::quit();
    }else if (ui -> mediumPizzaOption->isChecked()){
        QMessageBox::information(this, "Order", promptFirstHalf + "medium " + promptMiddle + " " + promptSecondHalf);
        QApplication::quit();
    }else if(ui -> smallPizzaOption -> isChecked()){
        QMessageBox::information(this, "Order", promptFirstHalf + "small " + promptMiddle + " "  + promptSecondHalf);
        QApplication::quit();
    }
}


void MainWindow::on_nameInput_textChanged(){
    if (ui->nameInput->toPlainText().isEmpty()){
            ui->promptNameError->show();
            return;
        }
    ui->promptNameError->hide();
}

void MainWindow::on_streetInput_textChanged(){
    if (ui->streetInput->toPlainText().isEmpty()){
            ui->promptStreetError->show();
            return;
        }
    ui->promptStreetError->hide();
}


void MainWindow::on_cityInput_textChanged(){
    if (ui->cityInput->toPlainText().isEmpty()){
            ui->promptCityError->show();
            return;
        }
    ui->promptCityError->hide();
}


void MainWindow::on_postalCodeInput_textChanged(){
    if (ui->postalCodeInput->toPlainText().isEmpty()){
            ui->promptPostalError->show();
            return;
        }
    ui->promptPostalError->hide();
}

