cmake_minimum_required(VERSION 3.5.0)
project(Mentoring VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(inc)
add_subdirectory(src)

add_executable(Mentoring main.cpp src/map/map.cpp)

target_include_directories(Mentoring PUBLIC inc/map)