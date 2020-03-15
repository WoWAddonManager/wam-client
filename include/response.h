//
// Created by jordan on 3/12/20.
//

#ifndef WAM_RESPONSE_H
#define WAM_RESPONSE_H

#include <string>
#include <cassert>

template <class T>
class Response {
public:
    ~Response() = default;
    Response() = delete;

    Response(const std::string &p_message, const int &p_error_code, const T &p_data) {
        this->m_message = p_message;
        this->m_error_code = p_error_code;
        this->m_data = p_data;

    }

    T get_data(){
        if(&(this->m_data))
            return this->m_data;
        else
            return T();

    }

    std::string get_message() {
        return this->m_message;
    }
    int get_error_code() {
        return this->m_error_code;
    }




private:
    std::string m_message = "";
    int m_error_code = 0;
    T m_data;


};


#endif //WAM_RESPONSE_H
