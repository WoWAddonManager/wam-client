#include <QApplication>
#include <libtorrent/session.hpp>
#include <string>
#include "mainwindow.h"
#include "upload_addon_dialog.h"
#include "settingsmanager.h"
#include "addon.h"
#include "login_dialog.h"
int main(int argc, char *argv[]) {
    QApplication wam(argc, argv);
    SettingsManager settings;
    login_dialog login;
//    MainWindow window(nullptr, settings);




    return QApplication::exec();

}
