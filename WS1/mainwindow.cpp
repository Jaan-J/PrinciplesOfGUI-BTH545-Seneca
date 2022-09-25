#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
  m_button = new QPushButton("Click Here", this);
  connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
}

void MainWindow::handleButton(){
  m_button->setText("Hello BTH545");
}
