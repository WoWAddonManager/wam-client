//
// Created by jordan on 12/24/19.
//

#ifndef WAM_SETTINGSMANAGER_H
#define WAM_SETTINGSMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h>
#include <sstream>
#include <QtCore/QString>
#include "httplib.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
class SettingsManager {
private:

    bool first_time = true;
    std::string m_base_wow_folder_path;
    std::string m_retail_addons_path = "";
    std::string m_classic_addons_path = "";
    std::string m_ptr_addons_path = "";
    std::string m_token = "";
public:
    [[nodiscard]] const std::shared_ptr<spdlog::logger> &get_logger() const;


private:
    std::string m_client = "";
    std::string m_uid = "";
    std::shared_ptr<spdlog::logger> m_logger;
    void generate_settings_file();

    static void generate_folder_structure();

    void update_settings_file(const std::string &field, const std::string &value);

    void update_settings_from_file();

public:

    //static constexpr char API_IP[] = "98.185.243.44";
    static constexpr char API_IP[] = "localhost";
    static constexpr int API_PORT = 3000;

    void update_token(const std::string &token);

    void update_client(const std::string &client);

    void update_uid(const std::string &uid);

    void populate_settings_file();

    std::string get_token();

    std::string get_client();

    std::string get_uid();

    SettingsManager();

    Json::Value settings_root;

    void set_wow_folder_paths();

    [[nodiscard]] std::string get_base_wow_path() const;

    void set_base_wow_path(const QString &path);

    [[nodiscard]] std::string get_retail_addons_path() const;
};

#endif //WAM_SETTINGSMANAGER_H
