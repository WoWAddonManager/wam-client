#include <QApplication>
#include <libtorrent/session.hpp>
#include <string>
#include "mainwindow.h"
#include "upload_addon_dialog.h"
#include "settingsmanager.h"
#include "addon.h"

int main(int argc, char *argv[]) {
    QApplication wam{argc, argv};
    SettingsManager settings{};
    MainWindow window{nullptr, settings};

    window.show();
    return QApplication::exec();

}
