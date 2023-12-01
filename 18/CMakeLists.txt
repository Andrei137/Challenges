cmake_minimum_required(VERSION 3.22)
project(Ascii)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

add_executable(Ascii Main.cpp)

# Find OpenCV package
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Link OpenCV libraries
target_link_libraries(Ascii ${OpenCV_LIBS})
