cmake_minimum_required(VERSION 3.19)
project(cloud-cafe-server)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES ./src)

add_executable(cloud-cafe-server main.cpp ./src ./include)
target_include_directories(cloud-cafe-server PUBLIC ./include ./apis/modern-cpp-kafka/include/ ${LIBRDKAFKA_ROOT}/include/)