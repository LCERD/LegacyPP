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

namespace LPP::GUI::Screens {
    EditScreen::EditScreen(IO::FileType type, QWidget *parent) {
        // main layout
        QWidget* mainLayout = new QWidget();
        this->mMainLayout = new QVBoxLayout(mainLayout);
        setLayout(this->mMainLayout);

        mMainLayout->setContentsMargins(0, 0, 0, 0);
        mMainLayout->setSpacing(0);

        QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

        // side layout
        QWidget* rightLayout = new QWidget();
        mRightLayout = new QGridLayout(rightLayout);

        // setup tabs
        this->mTabs = new QTabWidget(this);

        // make filelist
        this->mFileList = new Widgets::FileListWidget(type, this);

        // make toolbar
        QWidget *toolbar = new QWidget();
        QHBoxLayout *toolbarLayout = new QHBoxLayout(toolbar);
        toolbarLayout->setContentsMargins(0, 0, 0, 0);

        // make toolbar shit
        // QLabel* fileName = new QLabel("No file has been chosen", toolbar);
        mChooseFileButton = new QPushButton(QIcon::fromTheme("document-open"), "Choose a file", toolbar);
        connect(mChooseFileButton, &QPushButton::clicked, this, [type, this]() {
            onChooseFileButton(type);
        });

        mAddFileButton = new QPushButton(QIcon::fromTheme("document-new"), "Add file", toolbar);
        connect(mAddFileButton, &QPushButton::clicked, this->mFileList, &Widgets::FileListWidget::onAddFile);

        // add the shit to toolbar layout
        toolbarLayout->addWidget(mChooseFileButton);
        toolbarLayout->addWidget(mAddFileButton);

        // create left layout
        QWidget* leftLayout = new QWidget();
        mLeftLayout = new QVBoxLayout(leftLayout);

        // add tabs
        mRightLayout->addWidget(mTabs, 0, Qt::AlignTop);

        // add widgets
        mLeftLayout->addWidget(toolbar);
        mLeftLayout->addWidget(this->mFileList);

        splitter->addWidget(leftLayout);
        splitter->addWidget(rightLayout);

        this->mMainLayout->addWidget(splitter, 0);
    }

    bool EditScreen::onChooseFileButton(IO::FileType type) {
        // grab file
        QString fileName = QFileDialog::getOpenFileName(mFileList, "Choose a file");

        if (!fileName.isEmpty()) {
            // clear so that we don't have duplicates
            mFileList->clear();
            mTabs->clear();

            // read
            std::ifstream stream(fileName.toStdString(), std::ifstream::binary);

            std::vector<uint8_t> bytes(std::filesystem::file_size(fileName.toStdString()));
            stream.read(reinterpret_cast<char *>(bytes.data()), bytes.size());

            try {
                // read file
                lce::fs::Filesystem *file;
                switch (type) {
                    default:
                    case IO::FileType::BASIC:
                        file = new lce::fs::Filesystem();
                        break;
                    case IO::FileType::SAVE_FILE_OLD:
                    case IO::FileType::SAVE_FILE:
                        file = lce::save::SaveFileCommons::deserializeAuto(bytes);
                        break;
                    case IO::FileType::ARCHIVE:
                        file = new lce::arc::Archive(bytes);
                        break;
                    case IO::FileType::SOUNDBANK:
                        if (!lce::msscmp::Soundbank::isSoundbank(bytes.data())) {
                            QMessageBox::critical(this, "Invalid File", "This file is not a valid MSSCMP file");
                            return false;
                        }

                        file = new lce::msscmp::Soundbank(bytes);
                        break;
                }

                // add tab
                QWidget *saveTab = new QWidget();
                QVBoxLayout *saveTabLayout = new QVBoxLayout(saveTab);
                saveTabLayout->setSpacing(10);

                // TODO: make panel based on chosen file type
                // // create info strings
                // std::string v = "Version: " + std::to_string(file->getVersion());
                // std::string mv = "Original Version: " + std::to_string(file->getOriginalVersion());
                //
                // // add widgets
                // saveTabLayout->addWidget(new QLabel(v.c_str()));
                // saveTabLayout->addWidget(new QLabel(mv.c_str()));
                //
                // saveTabLayout->addStretch();

                // add the tab
                mTabs->addTab(saveTab, "Save File");

                // create list items in file list
                // TODO: this should read files and directories (recursively) instead of seeing all top level items as a file
                this->mFileList->create(file);
            } catch (const std::exception& e) {
                // Too Bad!
                std::string err = "Exception thrown whilst trying to read '" + fileName.toStdString() + "': " + e.what();
                QMessageBox::critical(mFileList, "Error", err.c_str());
            }
            return true;
        }
        return false;
    }
}
