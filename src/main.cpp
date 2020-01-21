#include <QApplication>
#include <libtorrent/session.hpp>
#include <string>
#include "mainwindow.h"
#include "upload_addon_dialog.h"
#include "settingsmanager.h"
#include "database.h"
#include "addon.h"


using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

int main(int argc, char *argv[]) {
    QApplication wam(argc, argv);
    auto *settings = new SettingsManager();
    auto *window = new MainWindow(nullptr, settings);
    auto *database = new Database();
//
//    auto cursor = database->addons_db.find(make_document(
//        kvp("name", bsoncxx::types::b_regex{"Addon"})
//    ));
//    for(auto doc : cursor){
//        std::cout << bsoncxx::to_json(doc) << std::endl;
//    }

    Addon::get_installed_adddons(Addon::WoWVersion::Retail);

    window->show();


    return QApplication::exec();

}
