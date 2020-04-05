//
// Created by jordan on 12/23/19.
//
#include <iostream>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <libtorrent/file_storage.hpp>
#include <libtorrent/settings_pack.hpp>
#include <libtorrent/session.hpp>
#include <libtorrent/create_torrent.hpp>

#include "addon.h"
#include "utils.h"
#include "httplib.h"



Addon Addon::create_addon(const std::string &addon_folder_path) {
    return Addon{};
}

Addon::Addon(const int64_t &id, const std::string &addon_name, const std::string &addon_version,
             const std::string &interface_version, const std::string &addon_note,
             const WoWVersion &wow_version) {
    this->m_addonName = addon_name;
    this->m_interface_version = interface_version;
    this->m_description = addon_note;
    this->m_addon_version = addon_version;
    this->m_wow_version = wow_version;

}

Addon::Addon(const Json::Value &addon_json) {
    this->m_addonName = addon_json["name"].asString();
    this->m_description = addon_json["description"].asString();
    this->m_addon_version = addon_json["version"].asString();
    this->m_torrent_info = addon_json["torrent_info"].asString();
    this->m_wow_version = WoWVersion::Retail;
}

std::vector<Addon> Addon::get_installed_adddons(const WoWVersion &wow_version) {
    boost::filesystem::directory_iterator dir_iter;
    switch (wow_version) {
        case WoWVersion::Retail:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/retail");
            break;
        case WoWVersion::Classic:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/classic");
            break;
        case WoWVersion::PTR:
            dir_iter = boost::filesystem::directory_iterator("./wam_files/ptr");
            break;
        default:
            break;
    }
    auto addons = std::vector<Addon>{};
    auto range = boost::make_iterator_range(dir_iter, {});
    for (const boost::filesystem::directory_entry &entry: range) {
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
    ss << addon.m_addonName << std::endl;
    ss << addon.m_addon_version << std::endl;
    ss << addon.m_description << std::endl;
    ss << addon.m_torrent_info << std::endl;
    os << ss.str();
    return os;
}

void Addon::make_wam(const std::string &folder_path) {
    this->generate_torrent_info(folder_path);
}

Response<std::vector<Addon>> Addon::get_remote_addons() {
    auto client = make_client();
    std::vector<Addon> addons{};
    auto result = client.Get("/api/addons");
    if(result && result->status == 200) {
        for (const Json::Value &addon : string_to_json(result->body)) {
            addons.emplace_back(addon);
        }
        Response<std::vector<Addon>> response("200 OK", result->status, addons);
        return response;
    }
    else if (!result){
        Response<std::vector<Addon>> response("503 Service Unavailable", 503, boost::none);
        return response;
    }
    else {
        Response<std::vector<Addon>> response(result->body, result->status, boost::none);
        return response;
    }
}

Response<Addon> Addon::get_addon_by_name(const std::string &addon_name) {
    auto client = make_client();
    auto result = client.Get(std::string("/api/addons?name=" + addon_name).c_str());
    if(result && result->status == 200) {
        Json::Value root = string_to_json(result->body);
        Addon addon(root);
        Response<Addon> response("200 OK", result->status, addon);
        return response;
    }
    else if (!result){
        Response<Addon> response("503 Service Unavailable", 503, boost::none);
        return response;
    }
    else {
        Response<Addon> response(result->body, result->status, boost::none);
        return response;
    }
}

void Addon::generate_torrent_info(const std::string &filepath) {
    libtorrent::settings_pack settings;
    libtorrent::session ses;
    settings.set_str(libtorrent::settings_pack::user_agent, "wam/" LIBTORRENT_VERSION);
    ses.apply_settings(settings);

    auto fs = lt::file_storage();
    boost::filesystem::recursive_directory_iterator dir_iter{filepath};
    auto range = boost::make_iterator_range(dir_iter, {});
    for (const boost::filesystem::directory_entry &entry: range) {
        if(!boost::filesystem::is_directory(entry)){
            fs.add_file(entry.path().string(), boost::filesystem::file_size(entry.path()));
        }
    }

    auto t = libtorrent::create_torrent(fs);
    t.set_comment(this->m_description.c_str());
    t.set_creator("WAM Client");
    t.add_tracker("http://192.168.1.14:8081/announce");
    t.set_priv(true);
    libtorrent::set_piece_hashes(t, ".");
    std::ostringstream out("my_torrent.torrent", std::ios_base::binary);

    bencode(std::ostream_iterator<char>(out), t.generate());

    this->m_torrent_info = out.str();

}

std::string Addon::wow_version_to_string(const Addon::WoWVersion &wow_version) {
    switch(wow_version){
        case WoWVersion::Retail:
            return std::string("Retail");
        case WoWVersion::Classic:
            return std::string("Classic");
        case WoWVersion::PTR:
            return std::string("PTR");
        default:
            return std::string("Invalid");
    }
}


Addon::WoWVersion Addon::wow_version_to_enum(const std::string &wow_version) {
    if(wow_version == "Retail")
        return WoWVersion::Retail;
    else if(wow_version == "Classic")
        return WoWVersion::Classic;
    else if(wow_version == "PTR")
        return WoWVersion::PTR;
    else
        return WoWVersion::Invalid;
}
