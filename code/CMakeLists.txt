cmake_minimum_required(VERSION 3.8)
project(ttt)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.65.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(ttt ${SOURCE_FILES})

target_link_libraries(ttt ${Boost_LIBRARIES})