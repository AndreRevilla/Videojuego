cmake_minimum_required(VERSION 3.10)

project(Mario)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    Main.cpp
    Map.cpp
    Mario.cpp
    Luigi.cpp
)

set(HEADERS
    Character.h
    Global.h
    Map.h
    Mario.h
    Luigi.h 
)

add_executable(Mario ${SOURCES} ${HEADERS})

target_include_directories(MyGameProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(MyGameProject sfml-graphics sfml-window sfml-system)

# Opcional: Si estás usando alguna librería externa adicional, puedes linkearla aquí
# target_link_libraries(MyGameProject PRIVATE nombre_de_la_libreria)