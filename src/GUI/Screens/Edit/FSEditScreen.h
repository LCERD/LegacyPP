//
// Created by DexrnZacAttack on 9/12/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_FSEDITSCREEN_H
#define LEGACYPLUSPLUS_FSEDITSCREEN_H

#include <QObject>

#include "EditScreen.h"

namespace LPP::GUI::Screens::Edit {
    class FSEditScreen : public EditScreen {
    public:
        explicit FSEditScreen(IO::FileType type, QWidget *parent = nullptr);

        bool canSaveInPlace() override;
    private:
        Widgets::FileListWidget *mFileList;

    private slots:
        bool onChooseFileButton(IO::FileType type) override;
        void onSaveFileButton() override;
    };
}

#endif //LEGACYPLUSPLUS_FSEDITSCREEN_H
