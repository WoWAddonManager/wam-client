#include "settingsmanager.h"
#include "response.h"
#include "httplib.h"
#include "utils.h"
#include "user.h"

Response<User> User::login(const std::string &email, const std::string &password) {
    auto client = make_client();
    Json::Value root;
    root["email"] = email;
    root["password"] = password;

    auto response = client.Post(LOGIN_AUTH_ROUTE, root.toStyledString(), "application/json");
    if(response){
        if(response->status == 200){
            Json::Value json = string_to_json(response->body)["data"];
            User user;
            user.m_account_id = json["id"].asString();
            user.m_token = response->get_header_value("access-token");
            user.m_client_id = response->get_header_value("client");
            user.m_email = json["uid"].asString();
            user.m_display_name = json["username"].asString();
            return Response<User>(response->body, response->status, user);
        }
    }
    else {
        make_message_box("Server Offline?");
    }
    return Response<User>("", 0, boost::none);
}

Response<User> User::login(const std::string &token) {
    return Response<User>("", 0, boost::none);
}


/// Validates a user sessions, true if valid false otherwise.
Response<bool> User::validate() {
    return Response<bool>("", 0, false);
}

std::string User::get_display_name() const {
    return this->m_display_name;
}

std::string User::get_account_id() const {
    return this->m_account_id;
}

std::string User::get_email() const {
    return this->m_email;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "m_account_id: " << user.m_account_id << " m_display_name: " << user.m_display_name << " m_token: "
       << user.m_token << " m_client_id: " << user.m_client_id << " m_email: " << user.m_email;
    return os;
}
