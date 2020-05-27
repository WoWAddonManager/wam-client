//
// Created by jordan on 12/24/19.
//
#include <json/json.h>
#include <boost/filesystem.hpp>
#include <string>
#include "settingsmanager.h"
#include "utils.h"
#include "mainwindow.h"




void SettingsManager::set_wow_folder_paths() {
    this->settings_root["wow_path"] = this->get_base_wow_path();
    this->m_retail_addons_path = this->m_base_wow_folder_path + "/_retail_/Interface/AddOns";
    this->m_classic_addons_path = this->m_base_wow_folder_path + "/_classic_/Interface/AddOns";
    this->m_ptr_addons_path = this->m_base_wow_folder_path + "/_ptr_/Interface/AddOns";
    auto logger = this->m_logger;
    if(logger) {
        logger->info("Retail Addon Path: {}", this->m_retail_addons_path);
        logger->info("Classic Addon Path: {}", this->m_classic_addons_path);
        logger->info("PTR Addon Path: {}", this->m_ptr_addons_path);
    }

}

SettingsManager::SettingsManager() {
    this->m_logger = spdlog::get("SettingsManager");
    if(!this->m_logger){
       this->m_logger = initialize_logger("SettingsManager");
    }
    generate_settings_file();
    generate_folder_structure();
}

std::string SettingsManager::get_retail_addons_path() const {
    return this->m_retail_addons_path;
}

std::string SettingsManager::get_base_wow_path() const {
    return this->m_base_wow_folder_path;
}

void SettingsManager::set_base_wow_path(const QString &path) {
    this->m_base_wow_folder_path.assign(path.toStdString());
    set_wow_folder_paths();
}

void SettingsManager::generate_settings_file() {
    if (boost::filesystem::exists("settings.json")) {
        if (boost::filesystem::is_empty("settings.json")) {
            this->populate_settings_file();
        }
        else {
            update_settings_from_file();
        }
    }
    else {
        auto file = std::ofstream("settings.json");
        file.close();
        this->populate_settings_file();
    }
}

void SettingsManager::generate_folder_structure() {
    boost::filesystem::create_directories("wam_files");
    boost::filesystem::create_directories("wam_files/retail");
    boost::filesystem::create_directories("wam_files/classic");
    boost::filesystem::create_directories("wam_files/ptr");
}

void SettingsManager::update_token(const std::string &token) {
    update_settings_file("token", token);
    this->m_token = token;
}

void SettingsManager::update_client(const std::string &client) {
    update_settings_file("client", client);
    this->m_client = client;
}

void SettingsManager::update_settings_file(const std::string &field, const std::string &value) {

    this->settings_root = string_to_json(read_file_to_string("settings.json"));
    this->settings_root[field] = value;
    std::ofstream file("settings.json");
    file << this->settings_root;
    file.close();
}

void SettingsManager::update_uid(const std::string &uid) {
    update_settings_file("uid", uid);
    this->m_uid = uid;
}

std::string SettingsManager::get_token() {
    return this->m_token;
}

std::string SettingsManager::get_client() {
    return this->m_client;
}

std::string SettingsManager::get_uid() {
    return this->m_uid;
}

void SettingsManager::update_settings_from_file() {
    this->settings_root = string_to_json(read_file_to_string("settings.json"));
    this->m_base_wow_folder_path = this->settings_root["wow_path"].asString();
    this->set_wow_folder_paths();
    this->first_time = this->settings_root["first_time"].asBool();
    this->m_token = this->settings_root["token"].asString();
    this->m_client = this->settings_root["client"].asString();
    this->m_uid = this->settings_root["uid"].asString();
}

void SettingsManager::populate_settings_file() {
    auto file = std::ofstream("settings.json");
    this->settings_root["wow_path"] = "";
    this->settings_root["token"] = "";
    this->settings_root["token"].setComment(std::string("//!!!DO NOT SHARE THIS!!!"), Json::commentBefore);
    this->settings_root["client"] = "";
    this->settings_root["client"].setComment(std::string("//!!!DO NOT SHARE THIS!!!"), Json::commentBefore);
    this->settings_root["uid"] = "";
    this->settings_root["uid"].setComment(std::string("//!!!DO NOT SHARE THIS!!!"), Json::commentBefore);
    this->settings_root["first_time"] = true;
    file << this->settings_root;
    file.close();
}

const std::shared_ptr<spdlog::logger> &SettingsManager::get_logger() const {
    return m_logger;
}

