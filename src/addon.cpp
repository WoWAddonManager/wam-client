//
// Created by jordan on 12/23/19.
//
#include <iostream>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <algorithm>
#include <boost/range/iterator_range_core.hpp>
#include "addon.h"
#include "utils.h"

Addon::Addon() = default;

std::shared_ptr<Addon> Addon::create_addon(const std::string &p_addon_folder_path) {
    std::string toc_content = utils::read_file_to_string(p_addon_folder_path);
    std::cout << parse_addon_name(toc_content) << std::endl;
    return std::make_shared<Addon>(Addon());
}

Addon::Addon(const std::string &p_addon_name, const std::string &p_addon_version, const std::string &p_interface_version,
             const std::string &p_addon_note) {
    this->m_addonName = p_addon_name;
    this->m_interface_version = p_interface_version;
    this->m_note = p_addon_note;
    this->m_addon_version = p_addon_version;

}

std::string Addon::parse_addon_name(const std::string &toc_file_content) {
    boost::regex expr("(## Title: )([\\sa-zA-Z]+)");
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;

    if (boost::regex_search(toc_file_content, what, expr, flags)) {
        return what[2].str();
    }
    else {
        return "No Name Found";
    }

}

std::string Addon::parse_interface_version(const std::string &toc_file_content) {
    boost::regex expr("(## Interface: )([0-9]+)");
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;

    if (boost::regex_search(toc_file_content.begin(), toc_file_content.end(), what, expr, flags)) {
        return what[2].str();
    }
    else {
        return "No Name Found";
    }
}

std::string Addon::parse_addon_version(const std::string &toc_file_content) {
    boost::regex expr("(## Version: )(.+?)\n");
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;

    if (boost::regex_search(toc_file_content, what, expr, flags)) {
        return what[2].str();
    }
    else {
        return "No Addon Version";
    }
}

std::string Addon::parse_note(const std::string &toc_file_content) {
    boost::regex expr("(## Notes: )([\\sa-zA-Z]+)");
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;

    if (boost::regex_search(toc_file_content, what, expr, flags)) {
        return what[2].str();
    }
    else {
        return "No Note Found";
    }
}

std::shared_ptr<std::vector<Addon>> Addon::get_all_adddons(const std::string &path) {
    auto addons = std::make_shared<std::vector<Addon>>();
    auto dir_iter = boost::filesystem::directory_iterator(path);
    auto range = boost::make_iterator_range(dir_iter, {});
    for(boost::filesystem::directory_entry &entry: range){
        if(boost::filesystem::is_directory(entry)) {
            auto iter = boost::filesystem::directory_iterator(entry.path());
            std::string toc_content;
            for (boost::filesystem::directory_entry &file:  boost::make_iterator_range(iter, {})) {
                if (boost::filesystem::extension(file) == ".toc") {
                    toc_content = utils::read_file_to_string(file.path().string());
                    auto addon_name = parse_addon_name(toc_content);
                    if(addon_name != "No Name Found"){
                        auto interface_version = parse_interface_version(toc_content);
                        auto addon_note = parse_note(toc_content);
                        auto addon_version = parse_addon_version(toc_content);
                        Addon addon(addon_name, addon_version, interface_version, addon_note);
                        addons->emplace_back(addon);
                    }

                }

            }

        }
    }
    return addons;
}

std::string Addon::get_path() const {
    return this->m_path;
}

void Addon::set_path(const std::string &path) {
    this->m_path = path;
}

std::ostream& operator<<(std::ostream &os,const  Addon &addon){
    std::stringstream ss;
    ss << addon.m_addonName + "\n";
    ss << addon.m_interface_version + "\n";
    ss << addon.m_note + "\n";
    os << ss.str();
    return os;
}



