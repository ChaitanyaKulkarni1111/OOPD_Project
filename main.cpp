#include <iostream>
#include <vector>
#include <ctime>
#include "AccessPoint.h"
#include "CommunicationMechanism.h"
#include "CommunicationProtocol.h"

using namespace std;

vector<pair<string, CommunicationProtocol*>> setupProtocols() {
    AccessPoint* apWiFi4 = new AccessPoint(1, 80);
    AccessPoint* apWiFi5 = new AccessPoint(2, 80);
    AccessPoint* apWiFi6 = new AccessPoint(3, 160);

    auto csma = new CommunicationMechanism("CSMA/CA", [](int numUsers) {
        cout << "CSMA/CA: Medium Access Control with backoff for " << numUsers << " users." << endl;
    });

    auto mimo = new CommunicationMechanism("MU-MIMO", [](int numUsers) {
        cout << "MU-MIMO: Multi-user communication for " << numUsers << " users." << endl;
    });

    auto ofdma = new CommunicationMechanism("OFDMA", [](int numUsers) {
        cout << "OFDMA: Frequency division for " << numUsers << " users." << endl;
    });

    WiFi4* wifi4 = new WiFi4(apWiFi4, csma);
    WiFi5* wifi5 = new WiFi5(apWiFi5, mimo);
    WiFi6* wifi6 = new WiFi6(apWiFi6, ofdma);

    return {{"WiFi 4", wifi4}, {"WiFi 5", wifi5}, {"WiFi 6", wifi6}};
}

void simulateWiFiCommunication(const vector<pair<string, CommunicationProtocol*>>& protocols, int numUsers) {
    for (const auto& protocol : protocols) {
        cout << protocol.first << endl;
        protocol.second->simulateCommunication(numUsers);
        double throughput = protocol.second->calculateThroughput(numUsers);
        double avgLatency = protocol.second->calculateAverageLatency(numUsers);
        double maxLatency = protocol.second->calculateMaxLatency(numUsers);
        cout << "Throughput: " << throughput << " Mbps" << endl;
        cout << "Average Latency: " << avgLatency << " ms" << endl;
        cout << "Maximum Latency: " << maxLatency << " ms" << endl;
    }
}

int main() {
    srand(time(0));

    auto protocols = setupProtocols();

    cout << "Simulation with 1 user:" << endl;
    simulateWiFiCommunication(protocols, 1);

    cout << "\nSimulation with 10 users:" << endl;
    simulateWiFiCommunication(protocols, 10);

    cout << "\nSimulation with 100 users:" << endl;
    simulateWiFiCommunication(protocols, 100);

    for (auto& protocol : protocols) {
        delete protocol.second;
    }

    return 0;
}
