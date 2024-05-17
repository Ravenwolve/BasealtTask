#include <basealttask/get.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <algorithm>
#include <set>
#include <thread>
#include <package.hpp>

static const std::string urlHeader = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

int main(int argc, char* argv[]) {
    if (argc == 1 || argv[1] == "help") {
            std::cout << "Usage: basealttask BRANCH1 BRANCH2\n\nThe utility for comparing two binary packages from ALT Repository export branches\n\nBranch example:\np9, p10, sisyphus\n\nCommand example:\nbasealttask p9 p10\n\n";
    }
    else if (argc != 3) {
        std::cout << "It is required to specify 2 branches!\n";
    }
    else {
        using namespace nlohmann;
        std::string firstBranch = argv[1], secondBranch = argv[2];

        std::set<BasealtTask::Package> firstSet;

        auto thread1 = std::thread([&firstBranch, &firstSet] {
            firstSet =  json::parse(BasealtTask::Get(urlHeader + firstBranch))["packages"].get<std::set<BasealtTask::Package>>();
        });
        auto secondSet = json::parse(BasealtTask::Get(urlHeader + secondBranch))["packages"].get<std::set<BasealtTask::Package>>();

        std::set<BasealtTask::Package> outerLeft, outerRight, inner1, inner2;
        std::vector<BasealtTask::Package> byVersionsFromFirst;

        thread1.join();

        std::set_difference(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), std::inserter(outerLeft, outerLeft.end()));
        std::set_difference(secondSet.begin(), secondSet.end(), firstSet.begin(), firstSet.end(), std::inserter(outerRight, outerRight.end()));

        std::set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), std::inserter(inner1, inner1.end()));
        std::set_intersection(secondSet.begin(), secondSet.end(), firstSet.begin(), firstSet.end(), std::inserter(inner2, inner2.end()));

        for (std::set<BasealtTask::Package>::iterator iter1 = inner1.begin(), iter2 = inner2.begin();
            iter1 != inner1.end() && iter2 != inner2.end(); ++iter1, ++iter2)
            if (iter1->version > iter2->version)
               byVersionsFromFirst.push_back(*iter1);

        json doc {
            { "OuterLeft", outerLeft },
            { "OuterRight", outerRight },
            { "VersionReleaseMoreFromLeft", byVersionsFromFirst }
        };

        std::cout << doc;
    }
}