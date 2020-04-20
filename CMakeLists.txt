cmake_minimum_required(VERSION 3.14)
project(VanillaCnn_Clion)

set(CMAKE_CXX_STANDARD 17)
set(INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE}")
message("alsjkdhaksjhdakjshd ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(VanillaCnn_Clion main.cpp)

add_subdirectory(src)
add_subdirectory(gtest)

target_link_libraries(VanillaCnn_Clion PUBLIC vanilla_lib)
target_link_libraries(VanillaCnn_Clion PUBLIC "-static")
message("cmake source dir: ${CMAKE_SOURCE_DIR}")