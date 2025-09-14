//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_MAINWINDOW_H
#define LEGACYPLUSPLUS_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "GUI/Screens/MainScreen.h"


class QStackedWidget;

namespace LPP::GUI::Windows {
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *p = nullptr);

        void switchScreen(const int s) const {
            mScreens->setCurrentIndex(s);
        };

        int addScreen(QWidget *s) const {
            return mScreens->addWidget(s);
        };

        int addScreenAtIndex(QWidget *s, const int i) const {
            return mScreens->insertWidget(i, s);
        };

    protected:
        QStackedWidget* mScreens;
        Screens::MainScreen *mMainScreen;
    };
}

#endif //LEGACYPLUSPLUS_MAINWINDOW_H
