
#ifndef CURL_H
#define CURL_H

#include <string>
#include <stdexcept>	
#include <curl/curl.h>

class curl {
public:
    curl(std::string url);
    curl(const curl& orig);
    virtual ~curl();
    void setUrl(std::string url);
    void setUrl();
    
private:
    CURL *curlObj = nullptr;
    CURLcode res;
    std::string url;
};

#endif /* CURL_H */

