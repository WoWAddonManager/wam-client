#include <QFile>
#include <QApplication>
#include <libtorrent/session.hpp>
#include "mainwindow.h"
#include "upload_addon_dialog.h"
#include "login_dialog.h"
#include "user.h"
#include "utils.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"


int main(int argc, char *argv[]) {
    QApplication wam(argc, argv);
    auto style = read_file_to_string("SyNet.qss");
    wam.setStyleSheet(QString::fromStdString(style));

    MainWindow mw(nullptr);
    mw.hide();

    // If the user is valid login them in and show them the main window.
    // if not show the login window.
    auto is_valid = User::validate();
    if (is_valid) {
        mw.show();
    }
    else {
        login_dialog login;
        login.exec();
    }


    return QApplication::exec();
}
