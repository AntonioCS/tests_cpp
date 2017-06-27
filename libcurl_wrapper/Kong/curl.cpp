
#include "curl.h"

curl::curl(std::string url) : url(url) {
    curlObj = curl_easy_init();
    
    if (!curlObj) {
        throw std::runtime_error("Unable to create curl object");
    }
}

curl::curl(const curl& orig) {
}

curl::~curl() {
    if (curlObj) {
        curl_easy_cleanup(curlObj);
    }
}

curl::setUrl(std::string url) {
    this->url = url;
    this->setUrl();
}

curl::setUrl() {
    curl_easy_setopt(curlObj, CURLOPT_URL, this->url.c_str());
}