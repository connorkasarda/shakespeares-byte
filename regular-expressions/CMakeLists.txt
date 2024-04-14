# =============================================================================
# This file is the CMake build system for the Regular Expressions (REGEX)
# program in Shakespeare's Byte.
# =============================================================================

# Sets the CMake version min requirement for Ubuntu
cmake_minimum_required(VERSION 3.22.1)

# Countermeasure if existing CMake version is too low
if($(CMAKE_VERSION) VERSION_LESS 3.22.1)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Defines the Shakespeare's Byte Regular Expression project
project(
    regular_expressions
    VERSION 2024.04.14
    DESCRIPTION "Regular Expressions for Shakespeare's Byte"
    LANGUAGES CXX)

# Names the application's include directories
set(INCLUDE_DIRS
    include)
    # more to come ...

# Names the application's source files
set(SOURCE_FILES
    source/regular_expressions.cpp)
    # more to come ...

# Establishes the regex library
add_library(regex_lib ${SOURCE_FILES})
target_include_directories(regex_lib PUBLIC ${INCLUDE_DIRS})

# Builds the regex executable
add_executable(regex_exe ${SOURCE_FILES})
target_link_libraries(regex_exe PRIVATE regex_lib)

# Sets executable's properties
set_target_properties(regex_exe PROPERTIES
    OUTPUT_NAME "regular_expressions")
