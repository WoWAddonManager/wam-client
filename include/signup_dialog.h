#ifndef WAM_SIGNUP_DIALOG_H
#define WAM_SIGNUP_DIALOG_H

#include "ui_signup_dialog.h"

namespace Ui {
    class signup_dialog;
}

class signup_dialog : public QDialog {
Q_OBJECT

public:
    explicit signup_dialog(QWidget *parent = nullptr);

    ~signup_dialog() override = default;

private:
    Ui::signup_dialog *dialog;
private slots:
};


#endif //WAM_SIGNUP_DIALOG_H
