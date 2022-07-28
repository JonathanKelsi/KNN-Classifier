cmake_minimum_required(VERSION 3.22)
project(AdvancedProgrammingAss1)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
    "classifier/Classified.h"
    "classifier/distance/Distance.h"
    "classifier/distance/EuclideanDistance.h"
    "classifier/distance/ManhattanDistance.h"
    )

set(PROJECT_SOURCES
        "classifier/Classified.cpp"
        "classifier/distance/EuclideanDistance.cpp"
        "classifier/distance/ManhattanDistance.cpp"
        "main.cpp")

add_executable(AdvancedProgrammingAss1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})


