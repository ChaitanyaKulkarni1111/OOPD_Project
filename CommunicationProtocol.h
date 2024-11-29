#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include "AccessPoint.h"
#include "CommunicationMechanism.h"

class CommunicationProtocol {
protected:
    AccessPoint* accessPoint;              // Protocol is tied to an access point
    CommunicationMechanism* mechanism;    // Communication mechanism
public:
    CommunicationProtocol(AccessPoint* ap, CommunicationMechanism* mech);
    virtual ~CommunicationProtocol() = default;

    virtual void simulateCommunication(int numUsers) = 0;
    virtual double calculateThroughput(int numUsers) = 0;
    virtual double calculateAverageLatency(int numUsers) = 0;
    virtual double calculateMaxLatency(int numUsers) = 0;
};

class WiFi4 : public CommunicationProtocol {
public:
    WiFi4(AccessPoint* ap, CommunicationMechanism* mech);
    void simulateCommunication(int numUsers) override;
    double calculateThroughput(int numUsers) override;
    double calculateAverageLatency(int numUsers) override;
    double calculateMaxLatency(int numUsers) override;
};

class WiFi5 : public CommunicationProtocol {
public:
    WiFi5(AccessPoint* ap, CommunicationMechanism* mech);
    void simulateCommunication(int numUsers) override;
    double calculateThroughput(int numUsers) override;
    double calculateAverageLatency(int numUsers) override;
    double calculateMaxLatency(int numUsers) override;
};

class WiFi6 : public CommunicationProtocol {
public:
    WiFi6(AccessPoint* ap, CommunicationMechanism* mech);
    void simulateCommunication(int numUsers) override;
    double calculateThroughput(int numUsers) override;
    double calculateAverageLatency(int numUsers) override;
    double calculateMaxLatency(int numUsers) override;
};

#endif // COMMUNICATIONPROTOCOL_H
