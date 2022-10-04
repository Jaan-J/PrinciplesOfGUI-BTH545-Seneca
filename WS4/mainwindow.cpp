#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *mainWindow = new QWidget;

    QDir directory(":/tool_icons");
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    QFile file ("./file.csv");


    std::vector<QToolButton*> buttons;
    size_t index = 0;
    foreach(QString filename, images) {
        buttonIconFileName.push_back(filename.toStdString());
        formatAndStoreNames(filename);
        QString iconFilePath = ":/tool_icons/" + filename;
        QToolButton* toolButtonBuffer = new QToolButton;

        toolButtonBuffer->setToolTip(formatAndStoreNames(filename));
        toolButtonBuffer->setIcon(QIcon(iconFilePath));
        buttons.push_back(toolButtonBuffer);


        if(file.open(QIODevice::ReadWrite | QFile::Append)){
            QTextStream stream(&file);
            stream << filename << "," << QString::fromStdString(formattedButtonNames_.at(index)) << "\n";
            file.close();
            ++index;
        }
    }


    QHBoxLayout* firstRowOfIcons = new QHBoxLayout();
    QHBoxLayout* secondRowOfIcons = new QHBoxLayout();
    QGridLayout*  gridLayout = new QGridLayout();



    for(size_t i = 0; i < buttons.size()/2; i++){
        firstRowOfIcons->addWidget(buttons.at(i));
    }

    for(size_t i = buttons.size()/2; i < buttons.size(); i++){
        secondRowOfIcons->addWidget(buttons.at(i));
    }

    gridLayout->addLayout(firstRowOfIcons,0,0,1,1);
    gridLayout->addLayout(secondRowOfIcons,1,0,1,1);


    mainWindow->setLayout(gridLayout);
    mainWindow->show();
}

QString MainWindow::formatAndStoreNames(QString rawFileName){
    std::string buffer = rawFileName.toStdString();
    std::size_t found = buffer.find_first_of("-");
    while (found!=std::string::npos){
        buffer[found]=' ';
        found=buffer.find_first_of("-",found+1);
    }
    size_t lastindex = buffer.find_last_of(".");
    std::string formattedName = buffer.substr(0, lastindex);
    formattedName[0] = toupper(formattedName[0]);
    for(size_t i = 0; i < formattedName.length(); i++){
       if (formattedName[i-1]== ' '){
            formattedName[i] = toupper(formattedName[i]);
        }
    }
    formattedButtonNames_.push_back(formattedName);
    return QString::fromStdString(formattedName);
}

