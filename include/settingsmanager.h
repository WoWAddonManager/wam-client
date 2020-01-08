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

class SettingsManager {
private:

    std::string m_base_wow_folder_path;
    std::string m_retail_addons_path;
    std::string m_classic_addons_path;
    std::string m_ptr_addons_path;

    bool first_time = true;
public:
    SettingsManager();
    Json::Value settings_root;
    void set_wow_folder_paths();
    std::string get_base_wow_path() const;
    void set_base_wow_path(const std::string &path);
    std::string get_retail_addons_path() const;





};


#endif //WAM_SETTINGSMANAGER_H
