//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#include "MainWindow.h"
#include <QStackedWidget>

namespace LPP::GUI::Windows {
    MainWindow::MainWindow(QWidget *p) : QMainWindow(p), mScreens(new QStackedWidget(this)), mMainScreen(new Screens::MainScreen(this)) {
        this->resize(800, 600);

        mScreens->addWidget(mMainScreen);

        setCentralWidget(mScreens);
    }
}
