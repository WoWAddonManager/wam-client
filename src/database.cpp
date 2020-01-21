//
// Created by jordan on 12/29/19.
//
#include <mongocxx/client.hpp>
#include <boost/format.hpp>
#include "database.h"


Database::Database() {
    #include "dbconfig.h"
    std::stringstream db_uri;
    db_uri << boost::format("mongodb://%s:%s@192.168.1.14:27017") % db_username % db_password;
    this->conn = {mongocxx::uri{db_uri.str()}};
    this->db = conn["wam"];
    this->users_db = this->db["users"];
    this->addons_db = this->db["addons"];

}
