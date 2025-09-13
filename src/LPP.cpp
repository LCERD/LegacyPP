//
// Created by zach on 9/1/25.
//
#include "LPP.h"

#include <iostream>
#include <ranges>
#include <QApplication>

#include "libLCEExports.h"
#include "GUI/Screens/EditScreen.h"

LPP::LegacyPlusPlus LPP::LegacyPlusPlus::sInstance = LegacyPlusPlus();

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LPP::LegacyPlusPlus::sInstance.run();
    return 0;
}

void LPP::LegacyPlusPlus::run() {
    lce::printLibraryInfo();
    std::cout << "Starting LegacyPlusPlus v" << LPP::LegacyPlusPlus::VERSION << "\n";

    this->mainWindow = new GUI::Windows::MainWindow();
    this->mainWindow->show();

    QApplication::instance()->exec();
}
