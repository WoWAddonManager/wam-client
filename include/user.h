#ifndef WAM_USER_H
#define WAM_USER_H
#include <string>
#include <ostream>

#include "response.h"
class User {
public:
    static Response<User> login(const std::string &email, const std::string &password);
    static Response<User> login(const std::string &token);
    static Response<bool> validate();

    std::string get_display_name() const;
    std::string get_account_id() const;
    std::string get_email() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

private:

    std::string m_account_id;
    std::string m_display_name;
    std::string m_token;
    std::string m_client_id;
    std::string m_email;

};
#endif //WAM_USER_H
