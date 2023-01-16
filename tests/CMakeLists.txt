cmake_minimum_required(VERSION 3.17)

project(Loggifyer_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/testMain.cpp"
)

add_executable(${PROJECT_NAME} ${SRCS})

# Set warning flags
if (MSVC)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        /WX # Treat all warnings as errors.
    )
else ()
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -std=c++20  # Use C++20
        -g3         # Memory debug mode.
    )
endif (MSVC)

target_link_libraries(${PROJECT_NAME} Loggifyer)

# Add the test to the project
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
