#include <package.hpp>

bool BasealtTask::Package::operator==(const Package &other) const {
    return name == other.name && source == other.source && arch == other.source;
}

bool BasealtTask::Package::operator!=(const Package &other) const {
    return !(*this == other);
}

bool BasealtTask::Package::operator>(const Package &other) const {
    return name > other.name && source > other.source && arch > other.source;
}

bool BasealtTask::Package::operator>=(const Package &other) const {
    return name >= other.name && source >= other.source && arch >= other.source;
}

bool BasealtTask::Package::operator<(const Package &other) const {
    return name < other.name && source < other.source && arch < other.source;
}

bool BasealtTask::Package::operator<=(const Package &other) const {
    return name <= other.name && source <= other.source && arch <= other.source;
}