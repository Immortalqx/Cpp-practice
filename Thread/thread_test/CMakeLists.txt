cmake_minimum_required(VERSION 3.20)
project(thread_test)

set(CMAKE_CXX_STANDARD 11)

link_libraries(pthread)

#add_executable(thread_test std_thread_demo.cpp)
add_executable(thread_test pthread_demo.cpp)
#add_executable(thread_test pthread_demo1.cpp)
#add_executable(thread_test pthread_demo2.cpp)
#add_executable(thread_test pthread_demo3.cpp)
