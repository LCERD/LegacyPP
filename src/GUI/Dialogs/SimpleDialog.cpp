//
// Created by DexrnZacAttack on 9/22/25 using zPc-i2.
//
#include "SimpleDialog.h"

#include <QVBoxLayout>

namespace LPP::GUI::Dialog {
    SimpleDialog::SimpleDialog(QWidget *parent) : QDialog(parent) {
        QWidget* mainWidget = new QWidget();
        QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
        setLayout(mainLayout);

        this->mBody = new QLabel(this);
        mainLayout->addWidget(this->mBody);
    }

    void SimpleDialog::setBody(const QString &b) const {
        this->mBody->setText(b);
    }
}
