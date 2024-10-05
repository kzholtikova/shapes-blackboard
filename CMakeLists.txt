cmake_minimum_required(VERSION 3.28)
project(shapes_blackboard)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(shapes_blackboard ${SOURCES} ${HEADERS})
