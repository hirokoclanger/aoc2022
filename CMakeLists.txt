cmake_minimum_required(VERSION 3.23)

project(aoc )

include_directories("range-v3/include/")
add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
target_link_libraries(${PROJECT_NAME} )
