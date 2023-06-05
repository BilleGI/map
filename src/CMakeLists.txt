cmake_minimum_required(VERSION 3.5)

add_executable(my_map main.cpp ${MY_INCLUDE_DIR}/mymap.h)

target_include_directories(my_map PUBLIC ${MY_INCLUDE_DIR})
