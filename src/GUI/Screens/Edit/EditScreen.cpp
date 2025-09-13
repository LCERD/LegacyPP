//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#include "EditScreen.h"

#include <fstream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSplitter>

#include "GUI/Widgets/FileListWidget.h"
#include "GUI/Widgets/FileListWidget.h"
#include "Save/SaveFile.h"

namespace LPP::GUI::Screens::Edit {
    EditScreen::EditScreen(IO::FileType type, QWidget *parent) {
        // main layout
        QWidget* mainLayout = new QWidget();
        this->mMainLayout = new QVBoxLayout(mainLayout);
        setLayout(this->mMainLayout);

        mMainLayout->setContentsMargins(0, 0, 0, 0);
        mMainLayout->setSpacing(0);
    }
}
