//
// Created by zach on 9/1/25.
//
#ifndef LEGACYPLUSPLUS_LEGACYPLUSPLUS_H
#define LEGACYPLUSPLUS_LEGACYPLUSPLUS_H

#include "GUI/Windows/MainWindow.h"

namespace LPP {
    class LegacyPlusPlus {
    public:
        static constexpr const char *const VERSION = LPP_VERSION;
        static LegacyPlusPlus sInstance;

        void run();
        void shutdown();

        GUI::Windows::MainWindow *mainWindow;
    };
}

#endif //LEGACYPLUSPLUS_LEGACYPLUSPLUS_H