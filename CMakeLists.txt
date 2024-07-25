cmake_minimum_required(VERSION 3.15)
project(MyTinyxml2)

include_directories(
    .
)

add_executable(main
    src/main.cpp
    util/tinyxml2.cpp
)