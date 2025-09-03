//
// Created by DexrnZacAttack on 9/2/25 using zPc-i2.
//
#include "MainScreen.h"

#include <fstream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>

#include "Save/SaveFile.h"

namespace LPP::GUI::Screens {
    MainScreen::MainScreen(QWidget *parent) {
        // main layout
        mLayout = new QGridLayout(this);

        // side layout
        QWidget* sideLayout = new QWidget();
        mSideLayout = new QGridLayout(sideLayout);

        // setup tabs
        this->mTabs = new QTabWidget(this);

        // make filelist
        this->mFileList = new QListWidget(this);

        // make toolbar
        QWidget *toolbar = new QWidget();
        QHBoxLayout *toolbarLayout = new QHBoxLayout(toolbar);
        toolbarLayout->setContentsMargins(0, 0, 0, 0);

        // make toolbar shit
        // QLabel* fileName = new QLabel("No file has been chosen", toolbar);
        QPushButton* chooseFileButton = new QPushButton("Choose a file", toolbar);

        // choose file button action
        QObject::connect(chooseFileButton, &QPushButton::clicked, this, &MainScreen::onChooseFileButton);

        // set stretch
        mLayout->setColumnStretch(0, 1);
        mLayout->setColumnStretch(1, 2);

        // add tabs
        mSideLayout->addWidget(mTabs, 0, Qt::AlignTop);

        // add the shit to toolbar layout
        // toolbarLayout->addWidget(fileName);
        toolbarLayout->addWidget(chooseFileButton);

        // add widgets
        mLayout->addWidget(this->mFileList, 1, 0);
        mLayout->addWidget(toolbar, 0, 0);
        mLayout->addWidget(sideLayout, 1, 1);
    }

    void MainScreen::onChooseFileButton() {
        // grab file
        QString fileName = QFileDialog::getOpenFileName(mFileList, "Choose a file", QDir::homePath());

        if (!fileName.isEmpty()) {
            // clear so that we don't have duplicates
            mFileList->clear();
            mTabs->clear();

            // read
            std::ifstream stream(fileName.toStdString(), std::ifstream::binary);

            std::vector<uint8_t> bytes(std::filesystem::file_size(fileName.toStdString()));
            stream.read(reinterpret_cast<char *>(bytes.data()), bytes.size());

            try {
                // read save file
                lce::save::SaveFileCommons *file = lce::save::SaveFileCommons::readAuto(bytes);

                // add tab
                QWidget *saveTab = new QWidget();
                QVBoxLayout *saveTabLayout = new QVBoxLayout(saveTab);

                // create info strings
                std::string v = "Version: " + std::to_string(file->getVersion());
                std::string mv = "Original Version: " + std::to_string(file->getOriginalVersion());

                // add widgets
                saveTabLayout->addWidget(new QLabel(v.c_str()));
                saveTabLayout->addWidget(new QLabel(mv.c_str()));

                // add the tab
                mTabs->addTab(saveTab, "Save File");

                // create list items in file list
                // TODO: this should read files and directories (recursively) instead of seeing all top level items as a file
                for (auto &f : file->getRoot()->getChildren()) {
                    QListWidgetItem* item = new QListWidgetItem(QString::fromWCharArray(f.first.c_str()));
                    item->setData(Qt::UserRole, QVariant::fromValue(&f));
                    mFileList->addItem(item);
                }

                // make them do shit
                connect(mFileList, &QListWidget::itemDoubleClicked, this, &MainScreen::onFileDoubleClicked);
            } catch (const std::exception& e) {
                // Too Bad!
                std::string err = "Exception thrown whilst trying to read '" + fileName.toStdString() + "': " + e.what();
                QMessageBox::critical(mFileList, "Error", err.c_str());
            }
        }
    }

    void MainScreen::onFileDoubleClicked(QListWidgetItem *item) {
        auto d = item->data(Qt::UserRole);
        const auto *p = d.value<const std::pair<const std::wstring, std::unique_ptr<lce::fs::FSObject>> *>();

        // todo: do something here
        // this->mSideLayout->addItem()
        // __builtin_trap();
    }
}
