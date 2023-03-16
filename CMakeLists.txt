cmake_minimum_required(VERSION 3.5)

project (projekt)

add_executable(${PROJECT_NAME} main.cpp pathfinding.cpp files.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/drogi.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/trasy.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/wyznaczone.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
