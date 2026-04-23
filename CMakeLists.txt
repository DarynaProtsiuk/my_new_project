cmake_minimum_required(VERSION 4.1)
project(my_new_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_new_project main.cpp
        Node.h
        SinglyLinkedList.h
        DoubleLinkedList.h)
