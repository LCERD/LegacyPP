//
// Created by DexrnZacAttack on 9/9/25 using zPc-i2.
//
#include "MainScreen.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "Edit/EditScreen.h"
#include "LPP.h"
#include "Factory/EditScreenFactory.h"

namespace LPP::GUI::Screens {
    MainScreen::MainScreen(QWidget *parent) {
        QWidget* mainLayout = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(mainLayout);
        layout->setSpacing(0);
        setLayout(layout);

        QLabel *label = new QLabel("Choose a file type");
        label->setContentsMargins(0, 0, 0, 5);

        this->mTypeComboBox = new QComboBox(mainLayout);
        this->mTypeComboBox->addItems(QStringList {
            CHOICE_SAVEFILE,
            CHOICE_ARCHIVE,
            CHOICE_SOUNDBANK
            });

        QWidget* buttonsLayout = new QWidget();
        QHBoxLayout *buttonsBoxLayout = new QHBoxLayout(buttonsLayout);

        QPushButton *button = new QPushButton("Open file");
        connect(button, &QPushButton::clicked, this, &MainScreen::onChooseFileButton);

        QPushButton *createButton = new QPushButton("Create new");
        connect(createButton, &QPushButton::clicked, this, &MainScreen::onCreateNewFileButton);

        buttonsBoxLayout->addWidget(button);
        buttonsBoxLayout->addWidget(createButton);

        layout->addWidget(label);
        layout->addWidget(this->mTypeComboBox);

        layout->addStretch();

        layout->addWidget(buttonsLayout);
    }

    void MainScreen::onChooseFileButton() {
        Edit::EditScreen *s = Factory::sEditScreenFactory.create(getFileType(), LegacyPlusPlus::sInstance.mainWindow).release();
        if (s->onChooseFileButton(getFileType())) { // this is file picker, returns false if nothing was picked
            const int i = LegacyPlusPlus::sInstance.mainWindow->addScreen(s);
            LegacyPlusPlus::sInstance.mainWindow->switchScreen(i);
        } else {
            s->setParent(nullptr); // dunno if this works like I want it to, since I have high doubts that the parent will ever delete this object, I decided to set the parent to null here and manage it ourselves
            delete s;
        }
    }

    void MainScreen::onCreateNewFileButton() {
        Edit::EditScreen *s = Factory::sEditScreenFactory.create(getFileType(), LegacyPlusPlus::sInstance.mainWindow).release();
        const int i = LegacyPlusPlus::sInstance.mainWindow->addScreen(s);
        LegacyPlusPlus::sInstance.mainWindow->switchScreen(i);
    }
}
