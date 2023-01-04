cmake_minimum_required(VERSION 3.17)

project(
    "Loggifyer"
    VERSION 0.1 DESCRIPTION "Easy to use and simple logging librairy using only macros"
    LANGUAGES CXX
)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(
        /WX # Anti basti-code argument that treat all warnings as errors.
    )
else ()
    add_compile_options(
        -Werror     # Anti basti-code argument that treat all warnings as errors.
        -Wall       # Enable all warnings even extra ones.
        -pedantic   # Enable pedantic warnings.
        -std=c++17  # Use c++17.
    )
endif (MSVC)

set(
    SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/Logger.cpp"
)

set(
    HDRS
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/PTP/Loggifyer.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/PTP/Loggifyer/Logger.hpp"
)

add_library(${PROJECT_NAME} STATIC ${SRCS} ${HDRS})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/"
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    ${PROJECT_NAME}
    ${PROJECT_NAME}
)

option(Loggifyer_BUILD_TESTS "Build the tests for Loggifyer" ON)

if (Loggifyer_BUILD_TESTS)
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests/")
endif ()
