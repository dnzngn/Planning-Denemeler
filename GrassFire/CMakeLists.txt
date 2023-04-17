cmake_minimum_required(VERSION 3.25)
project(Planning_Denemeler)

set(CMAKE_CXX_STANDARD 23)

include_directories(GrassFire)

add_executable(Planning_Denemeler
        GrassFire/mainGrass.cpp
        GrassFire/GrassFire.h)