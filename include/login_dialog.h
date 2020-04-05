#ifndef WAM_LOGIN_DIALOG_H
#define WAM_LOGIN_DIALOG_H

#include <QtWidgets/QMainWindow>
#include "ui_login_dialog.h"
namespace Ui {
    class login_dialog;
}

class login_dialog : public QDialog {
Q_OBJECT

public:
    explicit login_dialog(QWidget *parent = nullptr);

    ~login_dialog() override = default;

private:
    Ui::login_dialog *dialog;
private slots:
};

#endif //WAM_LOGIN_DIALOG_H
