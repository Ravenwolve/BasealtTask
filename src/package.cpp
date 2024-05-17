#include <package.hpp>

bool BasealtTask::Package::operator==(const Package &other) const {
    return name == other.name && source == other.source && arch == other.arch;
}

bool BasealtTask::Package::operator!=(const Package &other) const {
    return !(*this == other);
}

bool BasealtTask::Package::operator>(const Package &other) const {
    return name > other.name || name == other.name && source > other.source || source == other.source &&  arch > other.arch;
}

bool BasealtTask::Package::operator>=(const Package &other) const {
    return *this > other || *this == other;
}

bool BasealtTask::Package::operator<(const Package &other) const {
    return !(*this >= other);
}

bool BasealtTask::Package::operator<=(const Package &other) const {
    return !(*this > other);
}