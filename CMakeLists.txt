cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        brute_force.h
        input.h
        dynamic_prog.h
        greedy.h
        ilp.h)
