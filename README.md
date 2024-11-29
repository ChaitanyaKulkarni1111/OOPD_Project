# WiFi Simulator

This project simulates the behavior of different WiFi communication protocols (WiFi 4, WiFi 5, and WiFi 6) under various user scenarios. The simulator models communication mechanisms (CSMA/CA, MU-MIMO, and OFDMA) and calculates key metrics such as throughput, average latency, and maximum latency based on the number of users connected to an access point (AP).

## Project Structure

The project is organized into the following files:

- **main.cpp**: The entry point for the simulation. It sets up the protocols and runs the communication simulations for different user counts.
- **User.cpp / User.h**: Contains the `User` class, representing a user in the WiFi network.
- **AccessPoint.cpp / AccessPoint.h**: Contains the `AccessPoint` class, representing an access point in the network.
- **CommunicationMechanism.cpp / CommunicationMechanism.h**: Defines the abstract `CommunicationMechanism` class and its derived classes for different communication strategies (CSMA/CA, MU-MIMO, OFDMA).
- **CommunicationProtocol.cpp / CommunicationProtocol.h**: Contains the abstract `CommunicationProtocol` class and its derived classes (`WiFi4`, `WiFi5`, `WiFi6`), each implementing specific simulation logic and calculations.

## Prerequisites

- A C++ compiler supporting at least C++17 (e.g., `g++` version 10 or higher).
- `make` utility (optional for using the Makefile).

## Building the Project

### Using the Makefile

To build the project using the provided Makefile, run the following command in the project directory:

```bash
mingw32-make
