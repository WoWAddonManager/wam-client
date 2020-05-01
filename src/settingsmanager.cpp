//
// Created by jordan on 12/24/19.
//
#include <json/json.h>
#include <boost/filesystem.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include "settingsmanager.h"
#include "utils.h"
#include "mainwindow.h"



void SettingsManager::set_wow_folder_paths() {
    auto file = std::fstream("settings.json");
    this->settings_root["wow_path"] = this->get_base_wow_path();
    this->m_retail_addons_path = this->m_base_wow_folder_path + "/_retail_/Interface/AddOns";
    this->m_classic_addons_path = this->m_base_wow_folder_path + "/_classic_/Interface/AddOns";
    this->m_ptr_addons_path = this->m_base_wow_folder_path + "/_ptr_/Interface/AddOns";
    file << this->settings_root;
    file.close();
}

SettingsManager::SettingsManager() {
    generate_settings_file();
    generate_folder_structure();
}

std::string SettingsManager::get_retail_addons_path() const {
    return this->m_retail_addons_path;
}

std::string SettingsManager::get_base_wow_path() const {
    return this->m_base_wow_folder_path;
}

void SettingsManager::set_base_wow_path(const std::string &path) {
    this->m_base_wow_folder_path = path;
    set_wow_folder_paths();
}

void SettingsManager::generate_settings_file() {
    if (boost::filesystem::exists("settings.json") && boost::filesystem::is_empty("settings.json")) {
        this->settings_root["wow_path"] = "";
        this->settings_root["token"] = "";
        this->settings_root["client"] = "";
        this->settings_root["uid"] = "";
        this->settings_root["first_time"] = true;
        auto file = std::ofstream("settings.json");
        file << this->settings_root;
    }
    else {
        this->update_settings_from_file();
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
