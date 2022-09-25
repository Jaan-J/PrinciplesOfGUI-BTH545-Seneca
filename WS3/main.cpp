
#include <QLabel>
#include <QApplication>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Workshop 3");

    QLabel* title = new QLabel();
    title->setText("Jaans Pizza Shop");
    title->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    QHBoxLayout* titleBox = new QHBoxLayout();
    titleBox->addWidget(title);

    mainWindow->setLayout(titleBox);
    mainWindow->show();
    return a.exec();
}
