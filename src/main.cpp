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

    auto addons = Addon::get_remote_addons("");

    for(const auto &addon : addons){
        std::cout << addon;
    }

    window.show();
    return QApplication::exec();

}
