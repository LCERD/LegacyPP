//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_MAINSCREEN_H
#define LEGACYPLUSPLUS_MAINSCREEN_H

#include <qtabwidget.h>
#include <QWidget>

class QListWidget;
class QListWidgetItem;
class QGridLayout;

namespace LPP::GUI::Screens {
    class MainScreen : public QWidget {
        Q_OBJECT
    public:
        explicit MainScreen(QWidget *parent = nullptr);

        QTabWidget *mTabs;

        QGridLayout *mLayout;
        QGridLayout *mSideLayout;

        QListWidget *mFileList;

        QListWidgetItem *mChooseFileButton;

        private slots:
        void onChooseFileButton();
        void onFileDoubleClicked(QListWidgetItem *item);
    };
}

#endif //LEGACYPLUSPLUS_MAINSCREEN_H
