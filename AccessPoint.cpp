#include "AccessPoint.h"
#include <algorithm> // For std::min

AccessPoint::AccessPoint(int id, int bandwidth) 
    : id(id), bandwidthMHz(bandwidth), utilization(0.0) {}

int AccessPoint::getBandwidth() const {
    return bandwidthMHz;
}

void AccessPoint::updateUtilization(double usage) {
    utilization = std::min(1.0, utilization + usage);
}

double AccessPoint::getUtilization() const {
    return utilization;
}
