//
// Created by jordan on 12/23/19.
//
#include <iostream>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <libtorrent/file_storage.hpp>
#include "addon.h"
#include "utils.h"
#include "httplib.h"



Addon Addon::create_addon(const std::string &p_addon_folder_path) {
    return Addon{};
}

Addon::Addon(const int64_t &p_id, const std::string &p_addon_name, const std::string &p_addon_version,
             const std::string &p_interface_version, const std::string &p_addon_note,
             const WoWVersion &p_wow_version) {
    this->m_addonName = p_addon_name;
    this->m_interface_version = p_interface_version;
    this->m_description = p_addon_note;
    this->m_addon_version = p_addon_version;
    this->m_wow_version = p_wow_version;

}

Addon::Addon(const Json::Value &p_addon_json) {
    this->m_addonName = p_addon_json["name"].asString();
    this->m_description = p_addon_json["description"].asString();
    this->m_addon_version = p_addon_json["version"].asString();
    this->m_wow_version = WoWVersion::Retail;
}

std::vector<Addon> Addon::get_installed_adddons(const WoWVersion &p_wow_version) {
    boost::filesystem::directory_iterator dir_iter;
    switch (p_wow_version) {
        case WoWVersion::Retail:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/retail");
            break;
        case WoWVersion::Classic:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/classic");
            break;
        case WoWVersion::PTR:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/ptr");
            break;
    }
    auto addons = std::vector<Addon>{};
    auto range = boost::make_iterator_range(dir_iter, {});
    for (boost::filesystem::directory_entry &entry: range) {
        std::cout << entry.path().filename() << std::endl;
    }
    return addons;
}

std::string Addon::get_path() const {
    return this->m_path;
}

void Addon::set_path(const std::string &path) {
    this->m_path = path;
}

std::ostream &operator<<(std::ostream &os, const Addon &addon) {
    std::stringstream ss;
    ss << addon.m_addonName + "\n";
    ss << addon.m_interface_version + "\n";
    ss << addon.m_description + "\n";
    os << ss.str();
    return os;
}

void Addon::make_wam(const std::string &p_folder_path) {
    lt::file_storage fs;

}

Response<std::vector<Addon>> Addon::get_remote_addons() {
    httplib::Client client(SettingsManager::API_IP, 3000);
    std::vector<Addon> addons{};
    auto result = client.Get("/api/addons");
    if(result && result->status == 200) {
        for (const Json::Value &addon : utils::string_to_json(result->body)) {
            addons.emplace_back(addon);
        }
        Response<std::vector<Addon>> response("200 OK", result->status, addons);
        return response;
    }
    else {
        Response<std::vector<Addon>> response(result->body, result->status, addons);
        return response;
    }

}

Response<Addon> Addon::get_addon_by_name(const std::string &p_addon_name) {
    httplib::Client client(SettingsManager::API_IP, 3000);
    auto result = client.Get(std::string("/api/addons?name=" + p_addon_name).c_str());
    if(result && result->status == 200) {
        Json::Value root = utils::string_to_json(result->body);
        Addon addon(root);
        Response<Addon> response("200 OK", result->status, addon);
        return response;
    }
    else {
        Addon *addon = nullptr;
        Response<Addon> response(result->body, result->status, *addon);
        return response;
    }
}

