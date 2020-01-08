//
// Created by jordan on 12/29/19.
//

#ifndef WAM_DATABASE_H
#define WAM_DATABASE_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <utils.h>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

class Database {
public:

    Database();

    template<class T, class U>
    Json::Value search_database(T &key, U &value) {
        Json::Value json;
       auto cursor  = this->addons_db.find(make_document(
            kvp(key, value)));
        for(auto doc : cursor){
            std::cout << bsoncxx::to_json(doc) << std::endl;
        }
        return json;
    }

    mongocxx::instance inst;
    mongocxx::client conn;
    mongocxx::database db;
    mongocxx::collection users_db;
    mongocxx::collection addons_db;


private:


};


#endif //WAM_DATABASE_H
