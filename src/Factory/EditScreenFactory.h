//
// Created by DexrnZacAttack on 9/12/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_EDITSCREENFACTORY_H
#define LEGACYPLUSPLUS_EDITSCREENFACTORY_H
#include "../GUI/Screens/Edit/EditScreen.h"
#include "../GUI/Screens/Edit/FSEditScreen.h"

// knowledge comes from https://www.cppstories.com/2018/02/factory-selfregister/
namespace LPP::Factory {
    class EditScreenFactory {
    public:
        std::unique_ptr<GUI::Screens::Edit::EditScreen> create(IO::FileType type, QWidget *parent);

        // do we have to give custom name since it's a #define
#define EDITSCREEN_ADD_CREATOR(T, C) { \
        T, [](IO::FileType type, QWidget *parent) { return std::make_unique<C>(type, parent); } \
    }

    private:
        // Guess we're making EditScreens now
        using EditScreenCreator = std::function<std::unique_ptr<GUI::Screens::Edit::EditScreen>(IO::FileType type, QWidget *parent)>;

        // gotta use map instead of unordered_map otherwise I get some destructor weirdness
        std::map<IO::FileType, EditScreenCreator> mCreators {
            EDITSCREEN_ADD_CREATOR(IO::FileType::BASIC, GUI::Screens::Edit::FSEditScreen),
            EDITSCREEN_ADD_CREATOR(IO::FileType::SAVE_FILE, GUI::Screens::Edit::FSEditScreen),
            EDITSCREEN_ADD_CREATOR(IO::FileType::SAVE_FILE_OLD, GUI::Screens::Edit::FSEditScreen),
            EDITSCREEN_ADD_CREATOR(IO::FileType::ARCHIVE, GUI::Screens::Edit::FSEditScreen),
            EDITSCREEN_ADD_CREATOR(IO::FileType::SOUNDBANK, GUI::Screens::Edit::FSEditScreen)
        };
    };

    static EditScreenFactory sEditScreenFactory = EditScreenFactory();
}

#endif //LEGACYPLUSPLUS_EDITSCREENFACTORY_H
