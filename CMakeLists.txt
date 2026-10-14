cmake_minimum_required(VERSION 3.12)
project(MeinProjekt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_INCLUDES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/data"
    "${CMAKE_CURRENT_SOURCE_DIR}/header"
)

add_executable(app_main "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_include_directories(app_main PRIVATE ${MY_INCLUDES})

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/data/sensordaten.csv"
    "${CMAKE_CURRENT_BINARY_DIR}/sensordaten.csv"
    COPYONLY
)