#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <map>
#include <iostream>
#include <curl/curl.h>

namespace Kong {

    using std::cout;
    using std::string;
    using std::map;

    class Request {
    public:

        enum class MethodType {
            GET,
            POST,
            PUT,
            PATCH,
            DELETE
        };

        Request();
        Request(const Request& orig);
        virtual ~Request();

        void setHost(string host);
        string getHost() const;

        void setMethod(MethodType type);
        MethodType getMethod() const;
        void addParameter(string name, string value);
        const string &getParameter(const string name) const;

        //std::string execute() const;
        void execute() const;

    private:
        string host;
        map<string, string> parameters;
        MethodType method = MethodType::GET;

        static bool is_curl_init;

        CURL *curl;
        CURLcode res;
    };
}
#endif /* REQUEST_H */

