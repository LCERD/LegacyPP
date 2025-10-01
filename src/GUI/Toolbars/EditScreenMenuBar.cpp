//
// Created by DexrnZacAttack on 9/22/25 using zPc-i2.
//
#include "EditScreenMenuBar.h"

#include <QMenu>
#include <QToolButton>

#include "LPP.h"

namespace LPP::GUI::MenuBars {
    EditScreenMenuBar::EditScreenMenuBar(Screens::Edit::EditScreen *parent) : QMenuBar(parent) {
        QMenu *fileMenu = new QMenu("File", this);

        const QAction *openAction = fileMenu->addAction(QIcon::fromTheme("window-close"), "Close Editor");
        connect(openAction, &QAction::triggered, this, [parent]() {
            LegacyPlusPlus::sInstance.mainWindow->switchScreen(0);
        });

        QAction *saveAction = fileMenu->addAction(QIcon::fromTheme("document-save"), "Save");
        saveAction->setEnabled(parent->canSaveInPlace());
        connect(saveAction, &QAction::triggered, this, [parent]() {
            parent->onSaveFileButton();
        });

        // TODO: Save As

        this->addMenu(fileMenu);
    }
}
