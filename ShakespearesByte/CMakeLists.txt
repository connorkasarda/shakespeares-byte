# =============================================================================
# This file is the CMake build system for the Shakespeare's Byte project
# =============================================================================

# Sets the CMake version min requirement for Ubuntu
cmake_minimum_required(VERSION 3.22.1)

# Countermeasure if existing CMake version is too low
if($(CMAKE_VERSION) VERSION_LESS 3.22.1)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Defines the Shakespeare's Byte project
project(
    shakespeares_byte
    VERSION 2024.04.14
    DESCRIPTION "LLM text generator project for C++ projects"
    LANGUAGES CXX)

# Names the application's include directories
set(INCLUDE_DIRS
    include
    include/Tokenization)
    # more to come ...

# Names the application's source files
set(SOURCE_FILES
    source/Tokenization/BytePairEncoder.cpp
    source/main.cpp)
    # more to come ...

# Establishes the regex library
add_library(shakespeares_byte_lib ${SOURCE_FILES})
target_include_directories(shakespeares_byte_lib PUBLIC ${INCLUDE_DIRS})

# Builds the regex executable
add_executable(shakespeares_byte_exe ${SOURCE_FILES})
target_include_directories(shakespeares_byte_exe PRIVATE ${INCLUDE_DIRS})
target_link_libraries(shakespeares_byte_exe PRIVATE shakespeares_byte_lib)

# Sets executable's properties
set_target_properties(shakespeares_byte_exe PROPERTIES
    OUTPUT_NAME "shakespeares_byte")
