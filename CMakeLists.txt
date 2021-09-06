cmake_minimum_required(VERSION 3.20)
project(sorts)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#add_executable(laba1 src/main.cpp include/sorts.h src/sorts.cpp)

include_directories(include)

set(HEADERS
        include/sorts.h)

set(SOURCES
        src/main.cpp,
        src/sorts.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES})