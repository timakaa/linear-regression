# Makefile to configure, build and run using CMake and Conan

# Build directory
BUILD_DIR := build
RELEASE := true

ifeq ($(RELEASE),true)
    BUILD_TYPE := Release
else
    BUILD_TYPE := Debug
endif

install:
	conan install . -of=build --build=missing -g CMakeToolchain -g CMakeDeps

# Default target: configure, build and run
all: build run

# Configure and generate build files with CMake and Conan toolchain
configure:
	@cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	@cp build/compile_commands.json .

# Build target
build: configure
	cmake --build $(BUILD_DIR)

# Run target
run:
	./$(BUILD_DIR)/MyApp

frun: build run

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all configure build run clean

