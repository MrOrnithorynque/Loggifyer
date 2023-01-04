cmake_minimum_required(VERSION 3.17)

project(PTP_Loggifyer_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

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
        -g3         # Memory debug mode.
    )
endif (MSVC)

set(
    SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/testMain.cpp"
)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} Loggifyer)

# Add the test to the project
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
