#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace BasealtTask {
    struct Package {
        std::string name;
        size_t epoch;
        std::string version;
        std::string release;
        std::string arch;
        std::string disttag;
        uint64_t buildtime;
        std::string source;

        bool operator==(const Package& package) const;
        bool operator!=(const Package& package) const;
        bool operator>(const Package& package) const;
        bool operator>=(const Package& package) const;
        bool operator<(const Package& package) const;
        bool operator<=(const Package& package) const;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BasealtTask::Package, name, epoch, version, release, arch, disttag, buildtime, source)
}