#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow{
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
  void handleButton();
private:
  QPushButton *m_button;
};
#endif
