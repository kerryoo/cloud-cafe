cmake_minimum_required(VERSION 3.19)
project(cloud-cafe-server)

set(CMAKE_CXX_STANDARD 17)
include_directories(./include ./apis/modern-cpp-kafka/include/ ../../../../usr/local/Cellar/librdkafka/1.7.0/include)
add_library(./apis/modern-cpp-kafka/include/kafka/)
target_link_libraries(cloud-cafe-server kafka)

set(SOURCE_FILES ./src)

add_executable(cloud-cafe-server main.cpp src/User.cpp include/User.h src/Vector3.cpp include/Vector3.h src/UserList.cpp include/UserList.h include/ServerConfigs.h)