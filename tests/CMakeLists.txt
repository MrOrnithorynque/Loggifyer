cmake_minimum_required(VERSION 3.17)

project(PTP_Loggifyer_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set(
    SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/testMain.cpp"
)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PTP_Loggifyer)

# Add the test to the project
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
