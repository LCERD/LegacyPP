//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_EDITSCREEN_H
#define LEGACYPLUSPLUS_EDITSCREEN_H

#include <qboxlayout.h>
#include <QPushButton>
#include <qtabwidget.h>
#include <QWidget>

#include "Filesystem/File.h"
#include "GUI/Widgets/FileListWidget.h"

class QListWidget;
class QListWidgetItem;
class QGridLayout;

namespace LPP::GUI::Screens::Edit {
    class EditScreen : public QWidget {
        Q_OBJECT
    public:
        explicit EditScreen(IO::FileType type, QWidget *parent = nullptr);
    protected:
        QTabWidget *mTabs;

        QVBoxLayout *mMainLayout;

        QVBoxLayout *mLeftLayout;
        QGridLayout *mRightLayout;

        // TODO: this is not flexible for things that aren't files, such as LOC strings.
        // I think we can just make a new Screen type that extends off of EditScreen (once we gut mFileList from it)

        // File List Toolbar
        QPushButton *mChooseFileButton;
        QPushButton *mAddFileButton;

    public slots:
        virtual bool onChooseFileButton(IO::FileType type) = 0;
        // void onFileRightClicked(const QPoint &p);
    };
}

#endif //LEGACYPLUSPLUS_EDITSCREEN_H
