cmake_minimum_required(VERSION 3.17)

project(
    "Loggifyer"
    VERSION 0.1 DESCRIPTION "Easy to use and simple logging librairy using only macros"
    LANGUAGES CXX
)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.14)
        message(STATUS "MSVC version is greater than or equal to 19.14")
    endif()
endif()

set(
    SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/Logger.cpp"
)

set(
    HDRS
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/PTP/Loggifyer.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/PTP/Loggifyer/Logger.hpp"
)

set(LOGGIFYER_INCLUDE_DIR ${HDRS})

add_library(${PROJECT_NAME} STATIC ${SRCS} ${HDRS})

# Set warning flags
if (MSVC)

    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 17)
        message(FATAL_ERROR "MSVC version 17 or higher is required")
    endif()

    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        /WX         # Treat all warnings as errors.
    )

elseif (GCC)

    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -pedantic   # Enable pedantic warnings.
        -Werror     # Treat all warnings as errors.
        -Wall       # Enable all warnings, even extra ones.
        -std=c++20  # Use C++20.
    )

elseif (CLANG)

    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -Werror     # Treat all warnings as errors.
        -Wall       # Enable all warnings, even extra ones.
        -std=c++20  # Use C++20.
    )

endif (MSVC)

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
