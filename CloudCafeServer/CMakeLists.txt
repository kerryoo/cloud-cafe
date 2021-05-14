cmake_minimum_required(VERSION 3.19)
project(CloudCafeServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(CloudCafeServer main.cpp User.cpp User.h Vector3.cpp Vector3.h UserList.cpp UserList.h)