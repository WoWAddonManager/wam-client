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
#include "settingsmanager.h"

class Addon {
public:
    static std::shared_ptr<Addon> create_addon(const std::string &p_file_path);
    static std::shared_ptr<std::vector<Addon>> get_all_adddons(const std::string &path);

    friend std::ostream& operator<<(std::ostream &output, const Addon &addon);
    std::string m_addonName;
    std::string m_addon_version;
    std::string m_interface_version;
    std::string m_note;
    std::string m_path;

private:

    Addon();
    Addon(const std::string &p_addon_name, const std::string &p_addon_version, const std::string &p_interface_version, const std::string &p_addon_note);

    static std::string parse_addon_name(const std::string &toc_file_content);
    static std::string parse_interface_version(const std::string &toc_file_content);
    static std::string parse_addon_version(const std::string &toc_file_content);
    static std::string parse_note(const std::string &toc_file_content);

    std::string get_path() const;
    void set_path(const std::string &path);
};


#endif //WAM_ADDON_H
