#include <string>
#include <json/json.h>

#ifndef WAM_UTILS_H
#define WAM_UTILS_H

namespace utils {
    std::string read_file_to_string(const std::string &path);
    Json::Value string_to_json(const std::basic_string<char> &string);
}


#endif //WAM_UTILS_H
