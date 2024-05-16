#include <basealttask/get.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <algorithm>
#include <set>
#include <package.hpp>

static const std::string urlHeader = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

void Help() {
    
}

// using Iter = std::set<BasealtTask::Package>::iterator;
// Iter MoreVersionRelease(Iter first1, Iter last1, Iter first2, Iter last2, Iter output_first) {
//     while (first1 != last1) {
//         if (first2 == last2)
//             return std::copy(first1, last1, output_first);
//         if (first1->name == first2->name && first1->) {

//         }
//     }
//  }

int main(int argc, char* argv[]) {
    if (argc == 1 || argv[1] == "help") {
        Help();
    }
    else if (argc != 3) {
        std::cout << "It is required to specify 2 branches!\n";
    }
    else {
        using namespace nlohmann;
        std::string firstBranch = argv[1], secondBranch = argv[2];
        auto firstSet = json::parse(BasealtTask::Get(urlHeader + firstBranch))["packages"].get<std::set<BasealtTask::Package>>();
        auto secondSet = json::parse(BasealtTask::Get(urlHeader + secondBranch))["packages"].get<std::set<BasealtTask::Package>>();
        std::set<BasealtTask::Package> outerLeft, outerRight;
        std::set_difference(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), std::inserter(outerLeft, outerLeft.end()));
        std::set_difference(secondSet.begin(), secondSet.end(), firstSet.begin(), firstSet.end(), std::inserter(outerRight, outerRight.end()));
        json result;

        json doc{
            { "OuterLeft", outerLeft },
            { "OuterRight", outerRight },
            //{ "VersionReleaseMoreFromLeft", versionReleaseMoreFromLeft }
        };
        std::cout << doc;
    }
}