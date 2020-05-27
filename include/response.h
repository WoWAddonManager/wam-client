//
// Created by jordan on 3/12/20.
//

#ifndef WAM_RESPONSE_H
#define WAM_RESPONSE_H

#include <string>
#include <boost/optional.hpp>
#include <iostream>

template<class T>
class Response {
public:
    ~Response() = default;

    explicit Response(const std::string &p_message, const boost::optional<T> &p_data) {
        this->m_message = p_message;
        this->m_data = p_data;
    }

    boost::optional<T> get_data() {
        return this->m_data;
    }

    std::string get_message() {
        return this->m_message;
    }

    friend std::ostream &operator<<(std::ostream &os, const Response<T> &response) {
        os << std::string("Message: ") << response.m_message << std::endl;
        return os;
    }


private:
    std::string m_message;
    boost::optional<T> m_data;


};


#endif //WAM_RESPONSE_H
