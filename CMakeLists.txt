cmake_minimum_required(VERSION 3.8)
project(ZombieGame)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DGLEW_STATIC)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") #CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using

set(SOURCE_FILES
        main.cpp
        MainGame.cpp
        MainGame.h Agent.cpp Agent.h Zombie.cpp Zombie.h Human.cpp Human.h Player.cpp Player.h Level.cpp Level.h)

add_executable(ZombieGame ${SOURCE_FILES})

include(FindPkgConfig)

find_package(Celofan REQUIRED)
include_directories(${CELOFAN_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CELOFAN_LIBRARY})

target_link_libraries(ZombieGame mingw32 SDL2main SDL2 glew32s opengl32)