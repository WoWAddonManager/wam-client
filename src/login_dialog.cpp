#include <iostream>
#include <boost/optional/optional_io.hpp>
#include <utils.h>
#include "login_dialog.h"
#include "user.h"
#include "mainwindow.h"
#include "settingsmanager.h"
#include "signup_dialog.h"

login_dialog::login_dialog(QWidget *parent) : QDialog(parent), dialog(new Ui::login_dialog) {
    dialog->setupUi(this);
    this->show();

    connect(dialog->pushButton, &QPushButton::clicked, [&, this]() {
        auto form = this->dialog;
        auto response = User::login(form->email->text().toStdString(), form->password->text().toStdString());
        if (response.get_data() == boost::none) {
            make_message_box(response.get_message());
        }
        else {
            SettingsManager sm;
            auto user = response.get_data();
            sm.update_client(user->get_client());
            sm.update_token(user->get_token());
            sm.update_uid(user->get_account_id());
            auto *window = new MainWindow(nullptr);
            window->show();
            this->close();
        }


    });

    connect(dialog->pushButton_2, &QPushButton::clicked, [this] {
        this->hide();
        signup_dialog signup_dialog;
        signup_dialog.exec();
    });

}
