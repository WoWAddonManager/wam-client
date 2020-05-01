#ifndef WAM_USER_H
#define WAM_USER_H
#include <string>
#include <ostream>

#include "response.h"
class User {
public:

    User(const std::string &account_id, const std::string &display_name, const std::string &token,
         const std::string &client_id, const std::string &email);

    User(const Json::Value &json);

    User() = default;

    static Response<User> login(const std::string &email, const std::string &password);

    static Response<User> signup(const std::string &username, const std::string &email, const std::string &password,
                                 const std::string &password_confirmation);

    Response<bool> validate();

    [[nodiscard]] std::string get_display_name() const;

    [[nodiscard]] std::string get_account_id() const;

    [[nodiscard]] std::string get_email() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

private:

    std::string m_account_id;
    std::string m_display_name;
    std::string m_token;
    std::string m_client_id;
    std::string m_email;

};
#endif //WAM_USER_H
