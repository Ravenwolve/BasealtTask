#include <basealttask/get.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <algorithm>
#include <set>

static const std::string urlHeader = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

void Help() {

}

int main(int argc, char* argv[]) {
    if (argc == 1 || argv[1] == "help") {
        Help();
    }
    else if (argc != 3) {
        std::cout << "It is required to specify 2 branches!\n";
    }
    else {
        std::string firstBranch = argv[1], secondBranch = argv[2];
        std::string firstPackage = BasealtTask::Get(urlHeader + firstBranch);
        std::string secondPackage = BasealtTask::Get(urlHeader + secondBranch);
        nlohmann::json data = nlohmann::json::parse(firstPackage);
        std::cout << data;
    }
}