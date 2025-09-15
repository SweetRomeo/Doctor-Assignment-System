cmake_minimum_required(VERSION 4.0)
project(DataBaseApp)

set(CMAKE_CXX_STANDARD 20)

include_directories(libs/sqlite3)
link_directories(libs/sqlite3)

add_executable(DataBaseApp main.cpp
        Hospital.h
        Hospital.cpp
        libs/sqlite3/sqlite3.c)

target_include_directories(DataBaseApp PRIVATE libs/sqlite3)
