#ifndef WAM_UTILS_H
#define WAM_UTILS_H

#include <string>
#include <json/json.h>
#include <spdlog/spdlog.h>
#include "httplib.h"

const static char BASE_AUTH_ROUTE[] = "/auth";
const static char LOGIN_AUTH_ROUTE[] = "/auth/sign_in";
const static char LOGOUT_AUTH_ROUTE[] = "/auth/sign_out";
const static char VALIDATE_TOKEN_ROUTE[] = "/auth/validate_token";


extern std::string read_file_to_string(const std::string &path);

Json::Value string_to_json(const std::basic_string<char> &string);

httplib::Client make_client();

void make_message_box(const std::string &message);

std::shared_ptr<spdlog::logger> initialize_logger(const std::string &name = "logger");

#endif //WAM_UTILS_H
