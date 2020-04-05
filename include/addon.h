//
// Created by jordan on 12/23/19.
//

#ifndef WAM_ADDON_H
#define WAM_ADDON_H
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <boost/serialization/access.hpp>
#include "settingsmanager.h"
#include "response.h"

class Addon {
public:

    enum WoWVersion {
        Retail,
        Classic,
        PTR,
        Invalid
    };
    std::string m_id;
    std::string m_addonName;
    std::string m_addon_version;
    std::string m_interface_version;
    std::string m_description;
    std::string m_path;
    std::string m_torrent_info;
    WoWVersion m_wow_version;

    static Addon create_addon(const std::string &addon_folder_path);
    static std::vector<Addon> get_installed_adddons(const WoWVersion &wow_version);
    static Response<std::vector<Addon>> get_remote_addons();
    static Response<Addon> get_addon_by_name(const std::string &addon_name);
    static std::string wow_version_to_string(const WoWVersion &wow_version);
    static WoWVersion wow_version_to_enum(const std::string &wow_version);

    void make_wam(const std::string &folder_path);
    void generate_torrent_info(const std::string &filepath);

    friend std::ostream& operator<<(std::ostream &output, const Addon &addon);

    Addon() = default;
    Addon(const int64_t &id, const std::string &addon_name, const std::string &addon_version,
          const std::string &interface_version, const std::string &addon_note,
          const WoWVersion &wow_version);

    explicit Addon(const Json::Value &addon_json);

private:
    [[nodiscard]] std::string get_path() const;
    void set_path(const std::string &path);

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & m_addonName;
        ar & m_addon_version;
        ar & m_interface_version;
        ar & m_description;
        ar & m_path;
        ar & m_wow_version;
        ar & m_torrent_info;
    }

};


#endif //WAM_ADDON_H
