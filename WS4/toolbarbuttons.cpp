#include "toolbarbuttons.h"

toolbarButtons::toolbarButtons(){
    QDir directory(":/tool_icons");
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    QFile file ("./file.csv");
    foreach(QString filename, images) {
       formatAndStoreNames(filename);
       if(file.open(QIODevice::ReadWrite | QFile::Append)){
           QTextStream stream(&file);
           stream << filename << "\n";
           file.close();
       }

    }
}

void toolbarButtons::formatAndStoreNames(QString rawFileName){
    std::string buffer = rawFileName.toStdString();
    std::size_t found = buffer.find_first_of("-");
    while (found!=std::string::npos){
        buffer[found]=' ';
        found=buffer.find_first_of("-",found+1);
    }
    size_t lastindex = buffer.find_last_of(".");
    std::string formattedName = buffer.substr(0, lastindex);
    formattedName[0] = toupper(formattedName[0]);
    for(int i = 0; i < formattedName.length(); i++){
       if (formattedName[i-1]== ' '){
            formattedName[i] = toupper(formattedName[i]);
        }
    }
    buttonNames_.push_back(formattedName);
}

QGridLayout* toolbarButtons::createHorizontalLayout(){
    QHBoxLayout* vLayout = new QHBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();
    QGridLayout*  gridLayout = new QGridLayout();

    for(int i = 0; i < buttonNames_.size()/2; i++){
        QToolButton* toolButtons = new QToolButton();
        toolButtons->setToolTip(QString::fromStdString(buttonNames_.at(i)));
        toolButtons->setIcon(QIcon(":/tool_icons/eyes.png"));
        vLayout->addWidget(toolButtons);
    }

    for(int i = buttonNames_.size()/2; i < buttonNames_.size(); i++){
        QToolButton* toolButtons = new QToolButton();
        toolButtons->setText(QString::fromStdString(buttonNames_.at(i)));
        toolButtons->setToolTip(QString::fromStdString(buttonNames_.at(i)));
        hLayout->addWidget(toolButtons);
    }
    gridLayout->addLayout(vLayout,0,0,1,1);
    gridLayout->addLayout(hLayout,0,1,1,1);

    return gridLayout;
};
