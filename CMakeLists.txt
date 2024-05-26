cmake_minimum_required(VERSION 3.27)
project(projectcpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)



add_executable(projectcpp
        main.cpp
        Models/Base_class/user.h
        Models/Base_class/user.cpp
        Models/Class1/Class1.cpp
        Models/Class1/Class1.h
        Models/Class2/Class2.cpp
        Models/Class2/Class2.h
        "Models/Depended class/Photo.cpp"
        "Models/Depended class/Photo.h"
        menu/CMenu.h
        menu/CMenu.cpp
        menu/CMenuItem.cpp
        menu/CMenuItem.h
        Models/MyVector/MyContainer.h
        Models/MyVector/MyContainer2.h)
