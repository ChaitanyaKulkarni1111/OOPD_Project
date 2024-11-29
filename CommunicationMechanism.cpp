#include "CommunicationMechanism.h"
#include <iostream>

CommunicationMechanism::CommunicationMechanism(const std::string& mechName, std::function<void(int)> func) 
    : name(mechName), communicateFunction(func) {}

void CommunicationMechanism::communicate(int numUsers) {
    communicateFunction(numUsers);
}

std::string CommunicationMechanism::getName() const {
    return name;
}
