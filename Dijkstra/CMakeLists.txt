cmake_minimum_required(VERSION 3.25)
project(Planning_Denemeler)

set(CMAKE_CXX_STANDARD 23)

include_directories(Dijkstra)

add_executable(Planning_Denemeler
        Dijkstra/Dijkstra.h
        Dijkstra/main.cpp)