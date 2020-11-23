cmake_minimum_required(VERSION 3.10)

project(Arkanoid)

set(ScriptPath src/)

add_executable(Arkanoid ${ScriptPath}main.cpp)

add_library(GameManager ${ScriptPath}GameManager.h ${ScriptPath}GameManager.cpp)
add_library(Keyboard ${ScriptPath}Keyboard.h ${ScriptPath}Keyboard.cpp)
add_library(Map ${ScriptPath}Map.h ${ScriptPath}Map.cpp)
add_library(Platform ${ScriptPath}Platform.h ${ScriptPath}Platform.cpp)
add_library(systemClear ${ScriptPath}systemClear.h ${ScriptPath}systemClear.cpp)

target_link_libraries(Arkanoid PUBLIC GameManager)
target_link_libraries(Arkanoid PUBLIC Keyboard)
target_link_libraries(Arkanoid PUBLIC Map)
target_link_libraries(Arkanoid PUBLIC Platform)
target_link_libraries(Arkanoid PUBLIC systemClear)
