#include <json/json.h>
#include <iostream>
#include <settingsmanager.h>
#include <QtWidgets/QMessageBox>
#include "utils.h"

std::string read_file_to_string(const std::string &path) {
    std::ifstream file = std::ifstream(path, std::ios::in);
    std::stringstream ss;
    ss << file.rdbuf();
    std::string content = ss.str();
    return content;
}

Json::Value string_to_json(const std::string &string) {
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

httplib::Client make_client() {
    return httplib::Client(SettingsManager::API_IP, SettingsManager::API_PORT);
}

void make_message_box(const std::string &message) {
    QMessageBox msg(QMessageBox::Information, " ", QString::fromStdString(message));
    msg.exec();
}

std::shared_ptr<spdlog::logger> initialize_logger(const std::string &name) {
    auto file_logger = spdlog::rotating_logger_mt(name, "logs/log.txt", 1048576 * 5, 3);
    file_logger->set_pattern("[%T] [%n] [%l] %v");
    file_logger->flush_on(spdlog::level::trace);
    return file_logger;
}
