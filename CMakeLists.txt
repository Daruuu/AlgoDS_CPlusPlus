cmake_minimum_required(VERSION 4.0)
project(AlgoDS_CPlusPlus)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(AlgoDS_CPlusPlus main.cpp
)

add_executable(basics-max main_templates.cpp
)

add_executable(pointer-ref
        prepare-interview-cpp/esentials-concepts-in-cplusplus/pointersAndReference.cpp
)
add_executable(stackVsHeap
        prepare-interview-cpp/esentials-concepts-in-cplusplus/stackVsHeap.cpp
)

add_executable( raii
#        prepare-interview-cpp/esentials-concepts-in-cplusplus/resource-management-RAII.cpp
        prepare-interview-cpp/esentials-concepts-in-cplusplus/raii_demo.cpp
)

add_executable( declar-definition
        prepare-interview-cpp/esentials-concepts-in-cplusplus/punto.cpp
)