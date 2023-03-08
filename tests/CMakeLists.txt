cmake_minimum_required(VERSION 3.20)

project(Loggifyer_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/TestLoggifyer.cpp"
)

# SETUP GTEST
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    ${PROJECT_NAME}
    ${SRCS}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${LOGGIFYER_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    Loggifyer
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# SET COMPILE FLAGS
if(MSVC)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        /WX # Treat all warnings as errors.
    )
elseif(GCC)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -pedantic # Enable pedantic warnings.
        -Werror # Treat all warnings as errors.
        -Wall # Enable all warnings, even extra ones.
        -std=c++20 # Use C++20.
    )
elseif(CLANG)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -Werror # Treat all warnings as errors.
        -Wall # Enable all warnings, even extra ones.
        -std=c++20 # Use C++20.
    )
endif(MSVC)

add_executable(
    "testMain"
    "testMain.cpp"
)

target_compile_options(
    "testMain"
    PRIVATE
    -pedantic # Enable pedantic warnings.
    -Werror # Treat all warnings as errors.
    -Wall # Enable all warnings, even extra ones.
    -std=c++20 # Use C++20.
    -g
)

target_include_directories(
    "testMain"
    PUBLIC
    ${LOGGIFYER_INCLUDE_DIR}
)

target_link_libraries(
    "testMain"
    Loggifyer
)
