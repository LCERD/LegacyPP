//
// Created by DexrnZacAttack on 9/22/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_EDITSCREENMENUBAR_H
#define LEGACYPLUSPLUS_EDITSCREENMENUBAR_H

#include <QMenuBar>
#include <QWidget>

#include "GUI/Screens/Edit/EditScreen.h"

namespace LPP::GUI::MenuBars {
    class EditScreenMenuBar : public QMenuBar {
        Q_OBJECT
    public:
        explicit EditScreenMenuBar(Screens::Edit::EditScreen *parent);
    };
}

#endif //LEGACYPLUSPLUS_EDITSCREENMENUBAR_H
