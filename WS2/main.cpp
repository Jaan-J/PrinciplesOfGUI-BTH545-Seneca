#include <QApplication>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QtGui>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Workshop 2");

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,10);
    QLabel *sliderIntValue = new QLabel();
    sliderIntValue->setText("0");
    QObject::connect(slider,&QSlider::valueChanged,[&](int value){
        sliderIntValue->setText(QString::number(value));
    });
    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(slider);
    firstRow->addWidget(sliderIntValue);

    QPushButton *decrementSlider = new QPushButton("-");
    QPushButton *incrementSlider = new QPushButton("+");
    QObject::connect(decrementSlider, &QPushButton::clicked, slider,[slider] () {
        if(slider->value()==0) {
            slider->setValue(10);
            return;
        }
        slider->setValue(slider->value() - 1 );
    });
    QObject::connect(incrementSlider, &QPushButton::clicked, slider,[slider] () {
        if(slider->value()==10) {
            slider->setValue(0);
            return;
        }
        slider->setValue(slider->value() + 1 );
    });
    QLabel *sliderTextValue = new QLabel();
    sliderTextValue->setText("Zero");
    QObject::connect(slider,&QSlider::valueChanged,[&](int value){
        if (value ==0){
            sliderTextValue->setText("Zero");
        }
        else if(value == 1){
            sliderTextValue->setText("One");
        }else if(value ==2){
            sliderTextValue->setText("Two");
        }else if(value ==3){
            sliderTextValue->setText("Three");
        }else if(value ==4){
            sliderTextValue->setText("Four");
        }else if(value ==5){
            sliderTextValue->setText("Five");
        }else if(value ==6){
            sliderTextValue->setText("Six");
        }else if(value ==7){
            sliderTextValue->setText("Seven");
        }else if(value ==8){
            sliderTextValue->setText("Eight");
        }else if(value ==9){
            sliderTextValue->setText("Nine");
        }else if(value ==10){
            sliderTextValue->setText("Ten");
        }
    });
    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(decrementSlider);
    secondRow->addWidget(sliderTextValue);
    secondRow->addWidget(incrementSlider);

    QGridLayout * gridLayout = new QGridLayout;
    gridLayout->addLayout(firstRow,0,0);
    gridLayout->addLayout(secondRow,1,0);

    mainWindow->setLayout(gridLayout);
    mainWindow->show();
    return a.exec();
}
