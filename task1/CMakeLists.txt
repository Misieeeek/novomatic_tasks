cmake_minimum_required(VERSION 3.28.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Novomatic_Task_1 VERSION 1.0)

add_executable(${PROJECT_NAME} task1.cpp ${SRC_FILES})
