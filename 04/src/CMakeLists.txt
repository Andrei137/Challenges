cmake_minimum_required(VERSION 3.22)

project(Markov)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

add_executable(${PROJECT_NAME} Main.cpp sources/Interface.cpp sources/MarkovGenerator.cpp)

target_include_directories(
    ${PROJECT_NAME} SYSTEM PRIVATE
    ext/include/rlutil
    ext/include
    includes
)