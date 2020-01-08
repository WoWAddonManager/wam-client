#include <QApplication>
#include <libtorrent/session.hpp>
#include <string>
#include "addon.h"
#include "mainwindow.h"
#include "settingsmanager.h"
#include "database.h"
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

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
    database->search_database("name", "Addon 3");
    window->show();


    return QApplication::exec();
}
