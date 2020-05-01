#include <iostream>
#include <QMainWindow>
#include "mainwindow.h"
#include "user.h"
#include "signup_dialog.h"
#include "utils.h"
signup_dialog::signup_dialog(QWidget *parent): QDialog(parent), dialog(new Ui::signup_dialog) {
    dialog->setupUi(this);

    connect(dialog->signup_button, &QPushButton::clicked, [&, this]{
        auto username = dialog->username->text().toStdString();
        auto email = dialog->email->text().toStdString();
        auto password = dialog->password->text().toStdString();
        auto password_confirmation = dialog->password_confirmation->text().toStdString();
        auto response = User::signup(username, email, password, password_confirmation);
        auto message = string_to_json(response.get_message());

        if(message["status"] == "error"){
            auto errors = message["errors"];

            // TODO Is there a better way to do this?
            if(errors.isMember("username"))
                dialog->username_error_label->setText(QString::fromStdString("Username " + message["errors"]["username"][0].asString()));
            else
                dialog->username_error_label->setText("");

            if(errors.isMember("email"))
                dialog->email_error_label->setText(QString::fromStdString("Email " + message["errors"]["email"][0].asString()));
            else
                dialog->email_error_label->setText("");

            if(errors.isMember("password"))
                dialog->password_error_label->setText(QString::fromStdString("Password " + message["errors"]["password"][0].asString()));
            else
                dialog->password_error_label->setText("");

            if(errors.isMember("password_confirmation"))
                dialog->confirm_password_error_label->setText(QString::fromStdString("Password confirmation " + message["errors"]["password_confirmation"][0].asString()));
            else
                dialog->confirm_password_error_label->setText("");

        }
        else {
            MainWindow mw(nullptr);
            this->close();
            mw.show();
        }

        std::cout << response;
    });
    connect(dialog->login_button, &QPushButton::clicked, [this] {
        this->close();
        login_dialog login_dialog;
        login_dialog.exec();
    });
}
