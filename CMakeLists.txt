cmake_minimum_required(VERSION 3.10)

project(Arkanoid)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
include_directories(${CURSES_INCLUDE_DIR})

set(ScriptPath src/)

add_executable(Arkanoid ${ScriptPath}main.cpp ${ScriptPath}Keyboard.cpp)

add_library(GameManager ${ScriptPath}GameManager.h ${ScriptPath}GameManager.cpp)
add_library(Keyboard ${ScriptPath}Keyboard.h ${ScriptPath}Keyboard.cpp)
add_library(Map ${ScriptPath}Map.h ${ScriptPath}Map.cpp)
add_library(Platform ${ScriptPath}Platform.h ${ScriptPath}Platform.cpp)
add_library(Ball ${ScriptPath}Ball.h ${ScriptPath}Ball.cpp)
add_library(Point ${ScriptPath}Point.h ${ScriptPath}Point.cpp)

target_link_libraries(Arkanoid PRIVATE Threads::Threads)
target_link_libraries(Arkanoid PRIVATE ${CURSES_LIBRARIES})

target_link_libraries(Arkanoid PUBLIC GameManager)
target_link_libraries(Arkanoid PUBLIC Keyboard)
target_link_libraries(Arkanoid PUBLIC Map)
target_link_libraries(Arkanoid PUBLIC Platform)
target_link_libraries(Arkanoid PUBLIC Ball)
target_link_libraries(Arkanoid PUBLIC Point)
