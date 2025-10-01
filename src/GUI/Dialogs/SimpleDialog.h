//
// Created by DexrnZacAttack on 9/22/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_SIMPLEDIALOG_H
#define LEGACYPLUSPLUS_SIMPLEDIALOG_H
#include <QDialog>
#include <QLabel>

/** Simple dialog with title and body */
namespace LPP::GUI::Dialog {
    class SimpleDialog : public QDialog {
        Q_OBJECT
    public:
        SimpleDialog(QWidget *parent = nullptr);

        void setBody(const QString &b) const;
    private:
        QLabel *mBody;
    };
}

#endif //LEGACYPLUSPLUS_SIMPLEDIALOG_H
