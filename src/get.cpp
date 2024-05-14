#include "get.hpp"
#include <curl/curl.h>
#include <iostream>

std::string BasealtTask::Get(const std::string& url) {
    std::string response;
    
    auto curl = curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
    *[](void* ptr, size_t size, size_t nmemb, void* userdata)->size_t {
        ((std::string*)userdata)->append((char*)ptr, size * nmemb);
        return size * nmemb;
    });
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return response;
}
