CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# All .cpp files in directory cpp/
SRCS := $(shell find cpp -name "*.cpp")

# Output binary
OUT := ./bin/app

# Default target
all: build

# Build all cpp files
build:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUT)

# Run the built app
run: build
	$(OUT)

clean:
	rm -f $(OUT)
