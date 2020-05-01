#include "response.h"
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
        else {
            return Response<User>(response->body, response->status, boost::none);
        }
    }
    else {
        make_message_box("Server Offline?");
    }

}

Response<User> User::signup(const std::string &username, const std::string &email, const std::string &password,
                            const std::string &password_confirmation) {

    auto client = make_client();
    Json::Value root;
    root["username"] = username;
    root["email"] = email;
    root["password"] = password;
    root["password_confirmation"] = password_confirmation;
    auto response = client.Post(BASE_AUTH_ROUTE, root.toStyledString(), "application/json");
    return Response<User>(response->body, response->status, boost::none);
}

//! \brief Validates a user session token. true if valid, false otherwise.
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

User::User(const std::string &account_id, const std::string &display_name, const std::string &token,
           const std::string &client_id,
           const std::string &email) {
    this->m_account_id = account_id;
    this->m_display_name = display_name;
    this->m_token = token;
    this->m_client_id = client_id;
    this->m_email = email;

}

User::User(const Json::Value &json) {
    this->m_account_id = json["uid"].asString();
    this->m_display_name = json["nickname"].asString();
    this->m_token = json["access-token"].asString();
    this->m_client_id = json["client"].asString();
    this->m_email = json["email"].asString();
}

