//
// Created by DexrnZacAttack on 9/9/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_MAINSCREEN_H
#define LEGACYPLUSPLUS_MAINSCREEN_H

#include <QMenu>
#include <QWidget>
#include <QComboBox>

#include "GUI/Widgets/FileListWidget.h"

#define ADD_CHOICE(c, s) static constexpr const char *CHOICE_##c = s

namespace LPP::GUI::Screens {
    class MainScreen : public QWidget {
        Q_OBJECT
    public:
        ADD_CHOICE(SAVEFILE, "Save File (Savegame.dat)");
        ADD_CHOICE(ARCHIVE, "Archive (.ARC)");
        ADD_CHOICE(SOUNDBANK, "MSSCMP");

        explicit MainScreen(QWidget *parent = nullptr);

        IO::FileType getFileType() const {
            switch (this->mTypeComboBox->currentIndex()) {
                case 0: return IO::FileType::SAVE_FILE; // when we use for save button we will give choice to save w/ old save file
                case 1: return IO::FileType::ARCHIVE;
                case 2: return IO::FileType::SOUNDBANK;
                default: return IO::FileType::BASIC;
            }
        };
    private:
        QComboBox *mTypeComboBox;
    private slots:
        void onChooseFileButton();
        void onCreateNewFileButton();
    };
}

#endif //LEGACYPLUSPLUS_MAINSCREEN_H
