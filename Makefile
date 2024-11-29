# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp User.cpp AccessPoint.cpp CommunicationMechanism.cpp CommunicationProtocol.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable name
TARGET = wifi_simulator

# Default target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files to .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule for running the simulation
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
