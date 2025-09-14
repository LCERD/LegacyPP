//
// Created by DexrnZacAttack on 9/12/25 using zPc-i2.
//
#include "EditScreenFactory.h"

namespace LPP::Factory {
    std::unique_ptr<GUI::Screens::Edit::EditScreen> EditScreenFactory::create(const IO::FileType type, QWidget *parent) {
        return mCreators[type](type, parent);
    }
}
