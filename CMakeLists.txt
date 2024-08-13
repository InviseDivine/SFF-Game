cmake_minimum_required(VERSION 3.5.0)
project(SFFGame)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES
    "src/*.cpp"
    "src/EscapeFromAmina/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)

include_directories(
    "include/"
)
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)