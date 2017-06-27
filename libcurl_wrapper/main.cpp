#include <iostream>
#include "Kong/Request.h"
//#include <curl/curl.h>

using namespace std;

int main(int argc, char **argv) {
    
    using KRMethodType = Kong::Request::MethodType;
    Kong::Request request;    
    
    request.setHost("http://example.com");
    request.setMethod(KRMethodType::POST);
    request.addParameter("teste", "1");
    
    request.execute();
    
    
    
    
/*
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        // example.com is redirected, so we tell libcurl to follow redirection 
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request, res will get the return code 
        res = curl_easy_perform(curl);
        // Check for errors 
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        }

        // always cleanup 
        curl_easy_cleanup(curl);
    }
*/
    return 0;
}

