#include "settingsmanager.h"
#include "response.h"
#include "utils.h"
#include "user.h"

Response<User> User::login(const std::string &email, const std::string &password) {
    auto client = make_client();
    Json::Value root;
    root["email"] = email;
    root["password"] = password;

    if (email.empty() || password.empty())
        return Response<User>("Username/password empty", boost::none);

    auto response = client.Post(LOGIN_AUTH_ROUTE, root.toStyledString(), "application/json");
    if (response) {
        if (response->status == 200) {
            Json::Value json = string_to_json(response->body)["data"];
            User user;
            user.m_account_id = json["uid"].asString();
            user.m_token = response->get_header_value("access-token");
            user.m_client_id = response->get_header_value("client");
            user.m_email = json["uid"].asString();
            user.m_display_name = json["username"].asString();
            return Response<User>(response->body, user);
        }
        else {
            return Response<User>(string_to_json(response->body)["errors"][0].asString(), boost::none);
        }
    }
    else {
        return Response<User>("Server offline, check back later.", boost::none);
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
    if (response) {
        auto user_json = string_to_json(response->body)["data"];
        user_json["access-token"] = response->get_header_value("access-token");
        user_json["client"] = response->get_header_value("client");
        user_json["uid"] = response->get_header_value("uid");
        return Response<User>(response->body, User(user_json));
    }
    else {
        return Response<User>(string_to_json(response->body)["error"][0].asString(), boost::none);
    }

}

Response<User> User::logout() {
    SettingsManager settings;
    httplib::Headers headers = {
        {"access-token", settings.get_token()},
        {"uid",          settings.get_uid()},
        {"client",       settings.get_client()}
    };
    auto client = make_client();
    auto response = client.Delete("/auth/sign_out", headers);

    return Response<User>(response->body, User(string_to_json(response->body)["data"]));
}

//! \brief Validates a user session token. true if valid, false otherwise.
bool User::validate() {
    auto client = make_client();
    SettingsManager sm;
    httplib::Headers headers = {
        {"access-token", sm.get_token()},
        {"uid",          sm.get_uid()},
        {"client",       sm.get_client()}
    };
    auto response = client.Get("/auth/validate_token", headers);
    std::cout << response->body << std::endl;
    auto body = string_to_json(response->body);

    return body["success"].asBool();
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

std::string User::get_token() const {
    return this->m_token;
}

std::string User::get_client() const {
    return this->m_client_id;
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




