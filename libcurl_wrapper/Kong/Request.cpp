
#include "Request.h"
namespace Kong {
    bool Request::is_curl_init = false;

    Request::Request() {


        if (Request::is_curl_init == false) {
           curl_global_init(CURL_GLOBAL_ALL);
        }

    }

    Request::Request(const Request& orig) {
    }

    Request::~Request() {
    }

    void Request::setHost(std::string host) {
        this->host = host;
    }

    std::string Request::getHost() const {
        return this->host;
    }

    void Request::setMethod(Request::MethodType type) {
        this->method = type;
    }

    Request::MethodType Request::getMethod() const {
        return this->method;
    }

    void Request::addParameter(std::string name, std::string value) {
        this->parameters[name] = value;
    }
/*
    const std::string &Request::getParameter(const std::string &name) const {
       return this->parameters.at(name);
    }
  */
    //std::string
    void Request::execute() const {


        cout << "Host: " << host << " - Method: ";
        string method_string;

        switch (method) {
            case MethodType::GET:
                method_string = "GET";
                break;
            case MethodType::POST:
                method_string = "POST";
                break;
            case MethodType::DELETE:
                method_string = "DELETE";
                break;
            case MethodType::PATCH:
                method_string = "PATCH";
                break;
            case MethodType::PUT:
                method_string = "PUT";
                break;
        }

        cout << method_string << '\n';

       /** std::cout << "Parameters:\n";
        for (auto const &p : this->parameters) {
            std::cout << "   Name: " << p.first << " - Value: " << p.second << '\n';
        }*/
    }
}
