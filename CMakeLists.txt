cmake_minimum_required(VERSION 3.26)
project(TreeLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(TreeLab main.cpp
        TreeNode.cpp
        TreeNode.h)
