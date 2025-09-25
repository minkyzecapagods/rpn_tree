# ============================
# rpn_tree CMake Configuration
# ============================

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.16)

# Project name and programming language
project(rpn_tree LANGUAGES CXX)

# ----------------------------
# Compiler configuration
# ----------------------------

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
# Make the standard mandatory
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable compiler-specific extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------
# Include directories
# ----------------------------

# Add the "include" directory to the list of header search paths
include_directories(${CMAKE_SOURCE_DIR}/include)

# ----------------------------
# Output directory for binaries
# ----------------------------

# Define where the executable will be generated
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ----------------------------
# Source files
# ----------------------------

set(SOURCES
    src/main.cpp
    src/io.cpp
    src/parser.cpp
    src/treeService.cpp
)

# ----------------------------
# Executable creation
# ----------------------------

# Create the executable "rpn_tree" from source files
add_executable(rpn_tree ${SOURCES})

# ----------------------------
# Installation rules
# ----------------------------

# Install the executable in /usr/local/bin (requires root permissions)
install(TARGETS rpn_tree DESTINATION /usr/local/bin)

# ----------------------------
# Custom "clear" target
# ----------------------------

# Create a target that removes the entire build and binary directories
add_custom_target(clear
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}
    COMMENT "Deleting build and binary directories..."
)
