cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
 

project(SpaceCar)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

add_executable(Spacecar src/main.cpp src/renderer.cpp src/spacecar.cpp src/controller.cpp src/weapon.cpp src/bullet.cpp src/game.cpp src/enemycar.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Spacecar ${SDL2_LIBRARIES})
