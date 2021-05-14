cmake_minimum_required(VERSION 3.19)
project(CloudCafeServer)

set(CMAKE_CXX_STANDARD 14)
include_directories(./include)
set(SOURCE_FILES ./src)

add_executable(CloudCafeServer main.cpp src/User.cpp include/User.h src/Vector3.cpp include/Vector3.h src/UserList.cpp include/UserList.h include/ServerConfigs.h)