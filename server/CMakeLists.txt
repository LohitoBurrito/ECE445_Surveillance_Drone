# Minimum version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(DroneServer VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories (adjust paths as needed)
include_directories(
    /usr/include
    /usr/include/boost
    /usr/include/nlohmann
)

# Source files
set(SOURCES
    src/main.cpp
    src/commandControl.cpp
)

# Add the executable target
add_executable(drone_server ${SOURCES})

# Link libraries (curl, pthread explicitly added)
target_link_libraries(
    drone_server
    PRIVATE
    curl
    pthread
)

# Add verbose output during compilation (optional)
set(CMAKE_VERBOSE_MAKEFILE ON)
