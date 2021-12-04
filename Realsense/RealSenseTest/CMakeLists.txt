cmake_minimum_required(VERSION 3.16)
project(RealSense)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_LIST)

find_package(OpenCV REQUIRED)
add_executable(RealSense main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set( CMAKE_BUILD_TYPE Debug )
set(DEPENDENCIES realsense2 )
target_link_libraries(RealSense ${DEPENDENCIES})