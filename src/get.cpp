#include "get.hpp"
#include <curl/curl.h>
#include <iostream>

std::string ALTRepo::Get(const std::string& url) {
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


// static size_t getAnswer(void* contents, size_t size, size_t nmemb, void* userp) {
//     ((std::string*)userp)->append((char*)contents, size * nmemb);
//     return size * nmemb;
// }

// int main() {
//     CURL* curl = curl_easy_init();
//     std::string answer;
//     curl_easy_setopt(curl, CURLOPT_URL, "https://rdb.altlinux.org/api/export/branch_binary_packages/p9");
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getAnswer);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
//     CURLcode res = curl_easy_perform(curl);

//     std::cout << answer;

//     curl_easy_cleanup(curl);
// }
