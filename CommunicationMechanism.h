#ifndef COMMUNICATIONMECHANISM_H
#define COMMUNICATIONMECHANISM_H

#include <string>
#include <functional>

class CommunicationMechanism {
private:
    std::string name;
    std::function<void(int)> communicateFunction;

public:
    CommunicationMechanism(const std::string& mechName, std::function<void(int)> func);
    void communicate(int numUsers);
    std::string getName() const;
};

#endif // COMMUNICATIONMECHANISM_H
