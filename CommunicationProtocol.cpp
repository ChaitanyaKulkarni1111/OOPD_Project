#include "CommunicationProtocol.h"
#include <iostream>
#include <cmath>
#include <algorithm> // For std::min

// CommunicationProtocol Constructor
CommunicationProtocol::CommunicationProtocol(AccessPoint* ap, CommunicationMechanism* mech)
    : accessPoint(ap), mechanism(mech) {}

// WiFi4 Implementation
WiFi4::WiFi4(AccessPoint* ap, CommunicationMechanism* mech) : CommunicationProtocol(ap, mech) {}

void WiFi4::simulateCommunication(int numUsers) {
    mechanism->communicate(numUsers);
}

double WiFi4::calculateThroughput(int numUsers) {
    double packetSizeBits = 1024 * 8.0;  // 1KB packet size in bits
    double transmissionTime = 1.0 / (accessPoint->getBandwidth() * 0.005);
    double utilization = std::min(1.0, 1.0 / numUsers);
    accessPoint->updateUtilization(utilization);
    return ((packetSizeBits / transmissionTime) * utilization / 1e6) * 1000;
}

double WiFi4::calculateAverageLatency(int numUsers) {
    return (0.0002 * numUsers + 0.001) * 100;
}

double WiFi4::calculateMaxLatency(int numUsers) {
    return (0.0007 * numUsers + 0.002) * 100;
}

// WiFi5 Implementation
WiFi5::WiFi5(AccessPoint* ap, CommunicationMechanism* mech) : CommunicationProtocol(ap, mech) {}

void WiFi5::simulateCommunication(int numUsers) {
    mechanism->communicate(numUsers);
}

double WiFi5::calculateThroughput(int numUsers) {
    double totalTime = 15e-3;
    double dataTransmitted = numUsers * 1024 * 8;  // 1KB packet size in bits
    return (dataTransmitted / totalTime) / 1e6;
}

double WiFi5::calculateAverageLatency(int numUsers) {
    return (0.0001 * numUsers + 0.002) * 100;
}

double WiFi5::calculateMaxLatency(int numUsers) {
    return (0.003 * numUsers + 0.004) * 100;
}

// WiFi6 Implementation
WiFi6::WiFi6(AccessPoint* ap, CommunicationMechanism* mech) : CommunicationProtocol(ap, mech) {}

void WiFi6::simulateCommunication(int numUsers) {
    mechanism->communicate(numUsers);
}

double WiFi6::calculateThroughput(int numUsers) {
    double totalTime = 5e-3;
    double subChannelBandwidth = accessPoint->getBandwidth() / numUsers;
    double dataTransmitted = numUsers * subChannelBandwidth * totalTime * 1e6;
    return (dataTransmitted / totalTime) / 1e6;
}

double WiFi6::calculateAverageLatency(int numUsers) {
    return (0.001 * numUsers + 0.003) * 100;
}

double WiFi6::calculateMaxLatency(int numUsers) {
    return (0.005 * std::sqrt(numUsers) + 0.006) * 100;
}
