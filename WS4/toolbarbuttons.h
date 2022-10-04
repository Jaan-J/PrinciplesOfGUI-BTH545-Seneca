#ifndef TOOLBARBUTTONS_H
#define TOOLBARBUTTONS_H
#include <string>
#include <vector>
#include <iostream>
#include "QString"
#include "QGridLayout"
#include "QToolButton"
#include "QDir"

#include "QDir"
class toolbarButtons
{
    std::vector <std::string> buttonNames_;
    bool isConfigurationSaved_ = false;
public:
    toolbarButtons();
    void formatAndStoreNames(QString rawFileName);
    std::vector<std::string> fetchButtonNames(){return buttonNames_;};
    QGridLayout *createHorizontalLayout();
};

#endif // TOOLBARBUTTONS_H
