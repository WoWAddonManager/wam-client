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
    if (boost::filesystem::exists("settings.json")) {
        if (!boost::filesystem::is_empty("settings.json")) {
            std::string content = utils::read_file_to_string("settings.json");
            Json::CharReaderBuilder builder;
            Json::CharReader *reader = builder.newCharReader();
            std::string errors;
            bool parsed = reader->parse(content.c_str(), content.c_str() + content.size(), &this->settings_root,
                                        &errors);
            if (!parsed) {
                std::cout << errors << std::endl;
            }
            this->m_base_wow_folder_path = this->settings_root["wow_path"].asString();
            this->first_time = this->settings_root["first_time"].asBool();
            this->set_wow_folder_paths();
        }
        else {
            this->settings_root["wow_path"] = "";
            this->settings_root["first_time"] = true;
            auto file = std::ofstream("settings.json");
            file << this->settings_root;
        }
    }
    else {
        auto file = std::ofstream("settings.json");
        this->settings_root["wow_path"] = "";
        this->settings_root["first_time"] = true;
        file << this->settings_root;

    }

    if(!boost::filesystem::exists("wam_files")){
        boost::filesystem::create_directories("wam_files");
        boost::filesystem::create_directories("wam_files/retail");
        boost::filesystem::create_directories("wam_files/classic");
        boost::filesystem::create_directories("wam_files/ptr");
    }
}

std::string SettingsManager::get_retail_addons_path() const {
    return this->m_retail_addons_path;
}

std::string SettingsManager::get_base_wow_path() const {
    return this->m_base_wow_folder_path;
}

void SettingsManager::set_base_wow_path(const std::string &path) {
    this->m_base_wow_folder_path = path;
}
