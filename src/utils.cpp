#include "utils.h"
#include <fstream>
#include <json/json.h>
#include <iostream>
std::string utils::read_file_to_string(const std::string &path) {
    std::ifstream file = std::ifstream(path, std::ios::in);
    std::stringstream ss;
    ss << file.rdbuf();
    std::string content = ss.str();
    return content;
}

Json::Value utils::string_to_json(const std::string &string){
    Json::Value json;
    Json::CharReaderBuilder builder;
    Json::CharReader *reader = builder.newCharReader();
    std::string errors;
    bool parsed = reader->parse(string.c_str(), string.c_str() + string.size(), &json,
                                &errors);
    if (!parsed) {
        std::cout << errors << std::endl;
        return json["error"];
    }
    else {
        return json;
    }
}