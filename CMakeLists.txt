cmake_minimum_required(VERSION 3.28)
project(cligfx)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/image.cpp
    src/sprite.cpp
    src/framebuffer.cpp
    src/transformable.cpp
    src/text.cpp
)

add_library(cligfx ${SOURCES})

target_include_directories(cligfx PUBLIC include)
target_include_directories(cligfx PRIVATE extlibs/headers)
