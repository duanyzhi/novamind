cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(novamind)

# to include a lib path you can:
# one:
# include_directories(BEFORE ${PROJECT_SOURCE_DIR}/src/)
# two:
# include_directories(/home/name/project/src)
# three:
set(include_path ${PROJECT_SOURCE_DIR})  # add include_directories
include_directories(${include_path})
MESSAGE("LIB PATH:" ${include_path})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")   # show all waring
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

file(GLOB SOURCES "test/relu_t.cpp", "core/*.cpp", "utils/*.cpp", "operators/*.cpp")  # add all cpp file

add_executable(main ${SOURCES}) 
