cmake_minimum_required(VERSION 4.2)
project(proj1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(proj1 main.cpp
        Game.cpp
        Game.h
        Paddle.cpp
        Paddle.h
        Ball.cpp
        Ball.h
)
target_link_libraries(proj1 PRIVATE SFML::Graphics SFML::Window SFML::System)

file(COPY arial.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR})